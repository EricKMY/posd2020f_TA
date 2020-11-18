#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"

class CompoundShapeTestSuite: public testing::Test {
protected:
    virtual void SetUp() {

        std::vector<TwoDimensionalCoordinate*> coordinates_1;
        coordinates_1.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates_1.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates_1.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_1 = new Ellipse("1", 4, 3);
        rectangle_2 = new Rectangle("2", 3, 4);
        triangle_3 = new Triangle("3", coordinates_1);

        shapes.push_back(ellipse_1);
        shapes.push_back(rectangle_2);
        shapes.push_back(triangle_3);
        compoundShape_7 = new CompoundShape("7", shapes);

        std::vector<TwoDimensionalCoordinate*> coordinates_2;
        coordinates_2.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates_2.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates_2.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_4 = new Ellipse("4", 4.2, 3.7);
        rectangle_5 = new Rectangle("5", 3.7, 4.2);
        triangle_6 = new Triangle("6", coordinates_2);
    }

    virtual void TearDown() {}

    std::list<Shape*> shapes = {};
    Shape* ellipse_1;
    Shape* rectangle_2;
    Shape* triangle_3;
    Shape* ellipse_4;
    Shape* rectangle_5;
    Shape* triangle_6;
    Shape* compoundShape_7;
};

TEST(CompoundShape, no_exception_for_constructor) {
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
    coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
    coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

    std::list<Shape*> shapes = {};

    shapes.push_back(new Ellipse("1", 4, 3));
    shapes.push_back(new Rectangle("2", 3, 4));
    shapes.push_back(new Triangle("3", coordinates));

    ASSERT_NO_THROW(CompoundShape("4", shapes));
}

TEST_F(CompoundShapeTestSuite, area) {
    ASSERT_NEAR(55.699, compoundShape_7->area(), ABS);
}

TEST_F(CompoundShapeTestSuite, perimeter){
    ASSERT_NEAR(48.849, compoundShape_7->perimeter(), ABS);
}

TEST_F(CompoundShapeTestSuite, info){
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape_7->info());
}

TEST_F(CompoundShapeTestSuite, color){
    ASSERT_EQ("transparent", compoundShape_7->color());
}

TEST_F(CompoundShapeTestSuite, add_shape) {
    shapes.clear();
    shapes.push_back(ellipse_1);

    compoundShape_7 = new CompoundShape("7", shapes);
    compoundShape_7->addShape(rectangle_2);
    compoundShape_7->addShape(triangle_3);

    EXPECT_NEAR(55.699, compoundShape_7->area(), ABS);
    EXPECT_NEAR(48.849, compoundShape_7->perimeter(), ABS);
    EXPECT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape_7->info());
}

TEST_F(CompoundShapeTestSuite, delete_shape_by_id){
    compoundShape_7->deleteShapeById("1");

    EXPECT_NEAR(18, compoundShape_7->area(), ABS);
    EXPECT_NEAR(26, compoundShape_7->perimeter(), ABS);
    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape_7->info());
}

TEST_F(CompoundShapeTestSuite, exception_for_delete_shape_by_id){
    try {
        compoundShape_7->deleteShapeById("-1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTestSuite, get_shape_by_id){
    Shape *shape = compoundShape_7->getShapeById("3");

    EXPECT_EQ("3", shape->id());
    EXPECT_NEAR(6, shape->area(), ABS);
    EXPECT_NEAR(12, shape->perimeter(), ABS);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(CompoundShapeTestSuite, exception_for_get_shape_by_id){
    try {
        compoundShape_7->getShapeById("-1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTestSuite, get_shape_by_id_level_3_tree_structure) {
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = {};
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    Shape *shape = compoundShape_7->getShapeById("9");

    ASSERT_EQ("9", shape->id());
    ASSERT_NEAR(21.54, shape->area(), ABS); //triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(27.8, shape->perimeter(),ABS);//triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}", shape->info());

    shape = compoundShape_7->getShapeById("8");

    ASSERT_EQ("8", shape->id());
    ASSERT_NEAR(70.360, shape->area(), ABS); //ellipse_1 48.8203, triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(53.047, shape->perimeter(), ABS);//ellipse_1 24.3893, triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Ellipse (4.200, 3.700), Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}", shape->info());


    ASSERT_EQ("7", compoundShape_7->id());
    ASSERT_NEAR(126.059, compoundShape_7->area(), ABS); //compoundShape 55.6991, ellipse_1 48.8203, triangle_3 6, rectangle_2 15.54
    ASSERT_NEAR(101.897, compoundShape_7->perimeter(), ABS);//compoundShape 47.1327, ellipse_1 24.3893, triangle_3 12, rectangle_2 15.8
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Ellipse (4.200, 3.700), Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}}", compoundShape_7->info());
}

TEST_F(CompoundShapeTestSuite, delete_shape_by_id_level_3_tree_structure){
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = {};
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------
    
    compoundShape_7->deleteShapeById("9");

    ASSERT_NEAR(104.519, compoundShape_7->area(), ABS);
    ASSERT_NEAR(74.097, compoundShape_7->perimeter(), ABS);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Ellipse (4.200, 3.700)}}", compoundShape_7->info());

    compoundShape_7->deleteShapeById("8");

    ASSERT_NEAR(55.699, compoundShape_7->area(), ABS);
    ASSERT_NEAR(48.849, compoundShape_7->perimeter(), ABS);
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", compoundShape_7->info());
}

TEST_F(CompoundShapeTestSuite, exception_for_get_shape_by_id_tree_structure){
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = {};
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    try {
        compoundShape_7->deleteShapeById("7");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }

    try {
        compoundShape_8->deleteShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }

    try {
        compoundShape_9->deleteShapeById("4");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }
}

TEST_F(CompoundShapeTestSuite, exception_for_delete_shape_by_id_tree_structure){
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes.clear();
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    //--------------------------------------------------

    try {
        compoundShape_7->getShapeById("7");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }

    try {
        compoundShape_8->getShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }

    try {
        compoundShape_9->getShapeById("4");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}