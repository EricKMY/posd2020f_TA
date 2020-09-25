#include <gtest/gtest.h>
#include "../src/complex_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

using namespace std;

class ComplexShapeTest: public testing::Test {
    protected:
    void SetUp() {
        ellipse = new Ellipse("1", 4, 3);
        rectangle = new Rectangle("2", 3, 4);
        vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle("3", triangleVector);

        shapes->push_back(ellipse);
        shapes->push_back(rectangle);
        shapes->push_back(triangle);


        ellipse2 = new Ellipse("5", 4.2, 3.7);
        rectangle2 = new Rectangle("6", 3.7, 4.2);
        triangle2 = new Triangle("7", triangleVector);

    }
    vector<Shape*> *shapes = new vector<Shape*>();

    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;

    Shape* ellipse2;
    Shape* rectangle2;
    Shape* triangle2;
};

TEST(ComplexShape, ExceptionForEmptyShapes) {
    vector<Shape*>* nullShapes = new vector<Shape*>();
    try {
        ComplexShape("4", nullShapes);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a complexShape shape!", e);
    }
}

TEST_F(ComplexShapeTest, Area) {
    Shape* complexShape = new ComplexShape("4", shapes);
    ASSERT_NO_THROW(complexShape->area());
}

TEST_F(ComplexShapeTest, Perimeter){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_NEAR(48.849, complex_shape->perimeter(), 0.001);
}

TEST_F(ComplexShapeTest, Info){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_EQ("Complex Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExceptionForColor){
    Shape* complex_shape = new ComplexShape("4", shapes);
    try {
        complex_shape->color();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("complexShape can't have color", e);
    }
}

TEST_F(ComplexShapeTest, Type){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_EQ("ComplexShape", complex_shape->type());
}

TEST_F(ComplexShapeTest, AddShape) {
    shapes->clear();
    shapes->push_back(ellipse);

    Shape* complex_shape = new ComplexShape("4", shapes);
    complex_shape->addShape(rectangle);
    complex_shape->addShape(triangle);

    ASSERT_NEAR(55.699, complex_shape->area(), 0.001);
    ASSERT_NEAR(48.849, complex_shape->perimeter(), 0.001);
    ASSERT_EQ("Complex Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, DeleteShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);
    complex_shape->deleteShapeById("1");

    ASSERT_EQ(18, complex_shape->area());
    ASSERT_EQ(26, complex_shape->perimeter());
    ASSERT_EQ("Complex Shape {Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExceptionForDeleteShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);

    try {
        complex_shape->deleteShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }
}

TEST_F(ComplexShapeTest, GetShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);
    Shape *shape = complex_shape->getShapeById("3");


    ASSERT_EQ("3", shape->id());
    ASSERT_EQ(6, shape->area());
    ASSERT_EQ(12, shape->perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(ComplexShapeTest, ExceptionForGetShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);

    try {
        complex_shape->getShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }
}


TEST_F(ComplexShapeTest, GetShapeById_lv3) {
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> *shapes2 = new vector<Shape*>();
    shapes2->push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> *shapes3 = new vector<Shape*>();
    shapes3->push_back(triangle2);
    shapes3->push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2->addShape(complex_shape3);
    complex_shape->addShape(complex_shape2);

    //--------------------------------------------------

    Shape *shape = complex_shape->getShapeById("9");

    ASSERT_EQ("9", shape->id());
    ASSERT_NEAR(21.54, shape->area(), 0.01); //triangle 6, rectangle 15.54
    ASSERT_NEAR(27.8, shape->perimeter(), 0.01);//triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}", shape->info());

    shape = complex_shape->getShapeById("8");

    ASSERT_EQ("8", shape->id());
    ASSERT_NEAR(70.360, shape->area(), 0.001); //ellipse 48.8203, triangle 6, rectangle 15.54
    ASSERT_NEAR(53.047, shape->perimeter(), 0.001);//ellipse 24.3893, triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Ellipse (4.200, 3.700), Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}", shape->info());

    // shape = complex_shape->getShapeById("4");

    ASSERT_EQ("4", complex_shape->id());
    ASSERT_NEAR(126.059, complex_shape->area(), 0.001); //complexShape 55.6991, ellipse 48.8203, triangle 6, rectangle 15.54
    ASSERT_NEAR(101.897, complex_shape->perimeter(), 0.001);//complexShape 47.1327, ellipse 24.3893, triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Complex Shape {Ellipse (4.200, 3.700), Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}}", complex_shape->info());
}

TEST_F(ComplexShapeTest, DeleteShapeById_lv3){
   Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> *shapes2 = new vector<Shape*>();
    shapes2->push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> *shapes3 = new vector<Shape*>();
    shapes3->push_back(triangle2);
    shapes3->push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2->addShape(complex_shape3);
    complex_shape->addShape(complex_shape2);

    //--------------------------------------------------
    
    complex_shape->deleteShapeById("9");

    ASSERT_NEAR(104.519, complex_shape->area(), 0.001);
    ASSERT_NEAR(74.097, complex_shape->perimeter(), 0.001);
    ASSERT_EQ("Complex Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Complex Shape {Ellipse (4.200, 3.700)}}", complex_shape->info());

    complex_shape->deleteShapeById("8");

    ASSERT_NEAR(55.699, complex_shape->area(), 0.001);
    ASSERT_NEAR(48.849, complex_shape->perimeter(), 0.001);
    ASSERT_EQ("Complex Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExceptionForDeleteShapeById_lv3){
   Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> *shapes2 = new vector<Shape*>();
    shapes2->push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> *shapes3 = new vector<Shape*>();
    shapes3->push_back(triangle2);
    shapes3->push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2->addShape(complex_shape3);
    complex_shape->addShape(complex_shape2);

    //--------------------------------------------------

    try {
        complex_shape->deleteShapeById("10");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }

    try {
        complex_shape2->deleteShapeById("4");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }

    try {
        complex_shape3->deleteShapeById("8");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }
}

TEST_F(ComplexShapeTest, ExceptionForGetShapeById_lv3){
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> *shapes2 = new vector<Shape*>();
    shapes2->push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> *shapes3 = new vector<Shape*>();
    shapes3->push_back(triangle2);
    shapes3->push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2->addShape(complex_shape3);
    complex_shape->addShape(complex_shape2);

    //--------------------------------------------------

    try {
        complex_shape->getShapeById("11");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }

    try {
        complex_shape2->getShapeById("3");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }

    try {
        complex_shape3->getShapeById("7123");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }
}
