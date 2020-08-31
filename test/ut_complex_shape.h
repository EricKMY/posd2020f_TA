#include <gtest/gtest.h>
#include "../src/complex_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

using namespace std;

class ComplexShapeTest: public testing::Test {
    protected:
    void SetUp() {
        ellipse = new Ellipse("1", 3, 4);
        rectangle = new Rectangle("2", 3, 4);
        vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle("3", triangleVector);

        shapes = new vector<Shape*>();
        shapes->push_back(ellipse);
        shapes->push_back(rectangle);
        shapes->push_back(triangle);
    }
    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;

    vector<Shape*>* shapes;
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
    ASSERT_NEAR(47.1327, complex_shape->perimeter(), 0.0001);
}

TEST_F(ComplexShapeTest, Info){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_EQ("Complex Shape {Ellipse (3.000, 4.000)\nRectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}


TEST_F(ComplexShapeTest, AddShape){
    shapes->clear();
    shapes->push_back(ellipse);

    Shape* complex_shape = new ComplexShape("4", shapes);
    complex_shape->addShape(rectangle);
    complex_shape->addShape(triangle);

    ASSERT_NEAR(55.6991, complex_shape->area(), 0.0001);
    ASSERT_NEAR(47.1327, complex_shape->perimeter(), 0.0001);
    ASSERT_EQ("Complex Shape {Ellipse (3.000, 4.000)\nRectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, DeleteShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);
    complex_shape->deleteShapeById("1");

    ASSERT_EQ(18, complex_shape->area());
    ASSERT_EQ(26, complex_shape->perimeter());
    ASSERT_EQ("Complex Shape {Rectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExecptionForDeleteShapeById){
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

TEST_F(ComplexShapeTest, ExecptionForGetShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);

    try {
        complex_shape->getShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }
}