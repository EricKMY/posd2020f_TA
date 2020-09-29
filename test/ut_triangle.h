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

TEST_F(TriangleTest, Type){
    Shape* triangle = new Triangle("1", triangleVector);
    ASSERT_EQ("Triangle", triangle->type());
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


TEST_F(TriangleTest, ExceptionForCallGetShapeById){
    Shape* triangle = new Triangle("1", triangleVector);
    try {
        getShapeById(triangle, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}