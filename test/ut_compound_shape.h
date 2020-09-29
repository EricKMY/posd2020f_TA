#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

using namespace std;

class CompoundShapeTest: public testing::Test {
    protected:
    virtual void SetUp() {

        vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_1 = new Ellipse("1", 4, 3);
        rectangle_2 = new Rectangle("2", 3, 4);
        triangle_3 = new Triangle("3", coordinates);

        shapes->push_back(ellipse_1);
        shapes->push_back(rectangle_2);
        shapes->push_back(triangle_3);

        ellipse_4 = new Ellipse("4", 4.2, 3.7);
        rectangle_5 = new Rectangle("5", 3.7, 4.2);
        triangle_6 = new Triangle("6", coordinates);
    }

    virtual void TearDown() {
        shapes->clear();
        delete ellipse_1;
        delete rectangle_2;
        delete triangle_3;
        delete ellipse_4;
        delete rectangle_5;
        delete triangle_6;
    }

    vector<Shape*> *shapes = new vector<Shape*>();

    Shape* ellipse_1;
    Shape* rectangle_2;
    Shape* triangle_3;
    Shape* ellipse_4;
    Shape* rectangle_5;
    Shape* triangle_6;
};

TEST(CompoundShape, ExceptionForEmptyShapes) {
    vector<Shape*>* nullShapes = new vector<Shape*>();
    try {
        CompoundShape("7", nullShapes);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a compound shape!", e);
    }
}

TEST_F(CompoundShapeTest, Area) {
    Shape* compoundShape = new CompoundShape("7", shapes);
    ASSERT_NEAR(55.699, compoundShape->area(), 0.001);
}

TEST_F(CompoundShapeTest, Perimeter){
    Shape* compoundShape = new CompoundShape("7", shapes);
    ASSERT_NEAR(48.849, compoundShape->perimeter(), 0.001);
}

TEST_F(CompoundShapeTest, Info){
    Shape* compoundShape = new CompoundShape("7", shapes);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape->info());
}

TEST_F(CompoundShapeTest, ExceptionForColor){
    Shape* compoundShape = new CompoundShape("7", shapes);
    try {
        compoundShape->color();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Compound shape don't have single color", e);
    }
}

TEST_F(CompoundShapeTest, AddShape) {
    shapes->clear();
    shapes->push_back(ellipse_1);

    Shape* compoundShape = new CompoundShape("7", shapes);
    compoundShape->addShape(rectangle_2);
    compoundShape->addShape(triangle_3);

    ASSERT_NEAR(55.699, compoundShape->area(), 0.001);
    ASSERT_NEAR(48.849, compoundShape->perimeter(), 0.001);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape->info());
}

TEST_F(CompoundShapeTest, DeleteShapeById){
    Shape* compoundShape = new CompoundShape("7", shapes);
    compoundShape->deleteShapeById("1");

    ASSERT_EQ(18, compoundShape->area());
    ASSERT_EQ(26, compoundShape->perimeter());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape->info());
}

TEST_F(CompoundShapeTest, ExceptionForDeleteShapeById){
    Shape* compoundShape = new CompoundShape("7", shapes);

    try {
        compoundShape->deleteShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTest, GetShapeById){
    Shape* compoundShape = new CompoundShape("7", shapes);
    Shape *shape = compoundShape->getShapeById("3");

    ASSERT_EQ("3", shape->id());
    ASSERT_EQ(6, shape->area());
    ASSERT_EQ(12, shape->perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(CompoundShapeTest, ExceptionForGetShapeById){
    Shape* compoundShape = new CompoundShape("7", shapes);

    try {
        compoundShape->getShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTest, GetShapeById_Lv3TreeStruct) {
    Shape* compoundShape_7 = new CompoundShape("7", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(triangle_6);
    shapes->push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    Shape *shape = compoundShape_7->getShapeById("9");

    ASSERT_EQ("9", shape->id());
    ASSERT_NEAR(21.54, shape->area(), 0.01); //triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(27.8, shape->perimeter(), 0.01);//triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}", shape->info());

    shape = compoundShape_7->getShapeById("8");

    ASSERT_EQ("8", shape->id());
    ASSERT_NEAR(70.360, shape->area(), 0.001); //ellipse_1 48.8203, triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(53.047, shape->perimeter(), 0.001);//ellipse_1 24.3893, triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Ellipse (4.200, 3.700), Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}", shape->info());


    ASSERT_EQ("7", compoundShape_7->id());
    ASSERT_NEAR(126.059, compoundShape_7->area(), 0.001); //compoundShape 55.6991, ellipse_1 48.8203, triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(101.897, compoundShape_7->perimeter(), 0.001);//compoundShape 47.1327, ellipse_1 24.3893, triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Ellipse (4.200, 3.700), Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}}", compoundShape_7->info());
}

TEST_F(CompoundShapeTest, DeleteShapeById_Lv3TreeStruct){
    Shape* compoundShape_7 = new CompoundShape("7", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(triangle_6);
    shapes->push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------
    
    compoundShape_7->deleteShapeById("9");

    ASSERT_NEAR(104.519, compoundShape_7->area(), 0.001);
    ASSERT_NEAR(74.097, compoundShape_7->perimeter(), 0.001);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Ellipse (4.200, 3.700)}}", compoundShape_7->info());

    compoundShape_7->deleteShapeById("8");

    ASSERT_NEAR(55.699, compoundShape_7->area(), 0.001);
    ASSERT_NEAR(48.849, compoundShape_7->perimeter(), 0.001);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape_7->info());
}

TEST_F(CompoundShapeTest, ExceptionForDeleteShapeById_Lv3TreeStruct){
    Shape* compoundShape_7 = new CompoundShape("7", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(triangle_6);
    shapes->push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    try {
        compoundShape_7->deleteShapeById("7");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }

    try {
        compoundShape_8->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }

    try {
        compoundShape_9->deleteShapeById("4");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTest, ExceptionForGetShapeById_Lv3TreeStruct){
    Shape* compoundShape_7 = new CompoundShape("7", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = new vector<Shape*>();
    shapes->push_back(triangle_6);
    shapes->push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    try {
        compoundShape_7->getShapeById("7");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }

    try {
        compoundShape_8->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }

    try {
        compoundShape_9->getShapeById("4");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}
