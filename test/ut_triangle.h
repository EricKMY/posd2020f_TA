#include <gtest/gtest.h>
#include <vector>
#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"
#include "../src/utility.h"

using namespace std;
class TriangleTest: public testing::Test {
    protected:
    void SetUp() {
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    }
    vector<TwoDimensionalCoordinate*> triangleVector;
};


TEST_F(TriangleTest, ConstructorNoException){
    ASSERT_NO_THROW(Triangle("1", triangleVector));
}

TEST(Triangle, ExceptionForVectorLessThanThree){
    vector<TwoDimensionalCoordinate*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, 4));
    try {
        Triangle("1", triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST(Triangle, ExceptionForVectorMoreThanThree){
    vector<TwoDimensionalCoordinate*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, 4));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(-3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, -4));
    try {
        new Triangle("1", triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST(Triangle, ExceptionForAreaIsZero){
    vector<TwoDimensionalCoordinate*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(-3, 0));
    try {
        new Triangle("1", triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST_F(TriangleTest, Area){
    Shape* triangle = new Triangle("1", triangleVector);
    ASSERT_EQ(6, triangle->area());
}

TEST_F(TriangleTest, Perimeter){
    Shape* triangle = new Triangle("1", triangleVector);
    ASSERT_EQ(12, triangle->perimeter());
}

TEST_F(TriangleTest, Info){
    Shape* triangle = new Triangle("1", triangleVector);
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle->info());
}

TEST_F(TriangleTest, DefaultColor){
    Shape* triangle = new Triangle("1", triangleVector);
    ASSERT_EQ("White", triangle->color());
}

TEST_F(TriangleTest, RedColor){
    Shape* triangle = new Triangle("1", triangleVector, "Red");
    ASSERT_EQ("Red", triangle->color());
}

TEST_F(TriangleTest, ExceptionForAddShape){
    Shape* triangle = new Triangle("1", triangleVector);
    try {
        triangle->addShape(new Triangle("1", triangleVector));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only Compound shape can add shape!", e);
    }
}

TEST_F(TriangleTest, ExceptionForDeleteShape){
    Shape* triangle = new Triangle("1", triangleVector);
    try {
        triangle->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only Compound shape can delete shape!", e);
    }
}
TEST_F(TriangleTest, ExceptionForGetShapeById){
    Shape* triangle = new Triangle("1", triangleVector);
    try {
        triangle->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only Compound shape can get shape!", e);
    }
}


TEST_F(TriangleTest, ExceptionWhenIteratorFirst){
    Shape* triangle = new Triangle("1", triangleVector);
    Iterator *it = triangle->createIterator();
    try {
        it->first();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST_F(TriangleTest, ExceptionWhenIteratorCurrentItem){
    Shape* triangle = new Triangle("1", triangleVector);
    Iterator *it = triangle->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST_F(TriangleTest, ExceptionWhenIteratorNext){
    Shape* triangle = new Triangle("1", triangleVector);
    Iterator *it = triangle->createIterator();
    try {
        it->next();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("no child member!", e);
    }
}

TEST_F(TriangleTest, IteratorIsDone){
    Shape* triangle = new Triangle("1", triangleVector);
    Iterator *it = triangle->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(TriangleTest, ExceptionForCallGetShapeById){
    Shape* triangle = new Triangle("1", triangleVector);
    try {
        getShapeById(triangle, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only complex shape can get shape!", e);
    }
}

TEST_F(TriangleTest, FilterShapeArea){
    Shape* triangle = new Triangle("1", triangleVector);
    vector<Shape *> vector = filterShape(triangle, AreaFilter(12, 1));

    ASSERT_EQ(6, vector[0]->area());


    vector = filterShape(triangle, AreaFilter(5, 1));

    ASSERT_EQ(0, vector.size());
}


TEST_F(TriangleTest, FilterShapePerimeter){
    Shape* triangle = new Triangle("1", triangleVector);
    vector<Shape *> vector = filterShape(triangle, PerimeterFilter(12, 1));

    ASSERT_EQ(6, vector[0]->area());


    vector = filterShape(triangle, PerimeterFilter(5, 1));

    ASSERT_EQ(0, vector.size());
}

TEST_F(TriangleTest, FilterShapeByColor){
    Shape* triangle = new Triangle("1", triangleVector);
    vector<Shape *> vector = filterShape(triangle, ColorFilter("White"));

    ASSERT_EQ("White", vector[0]->color());


    vector = filterShape(triangle, ColorFilter("Red"));

    ASSERT_EQ(0, vector.size());
}

TEST_F(TriangleTest, FilterShapeByType){
    Shape* triangle = new Triangle("1", triangleVector);
    vector<Shape *> vector = filterShape(triangle, TypeFilter("Triangle"));

    ASSERT_EQ("Triangle", vector[0]->type());


    vector = filterShape(triangle, TypeFilter("Rectangle"));

    ASSERT_EQ(0, vector.size());
}