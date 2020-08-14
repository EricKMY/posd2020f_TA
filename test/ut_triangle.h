#include "../src/triangle.h"



class TriangleTest: public testing::Test {
    protected:
    void SetUp() {
        triangleVector.push_back(new TwoDimensionalVector(0, 0));
        triangleVector.push_back(new TwoDimensionalVector(3, 0));
        triangleVector.push_back(new TwoDimensionalVector(0, 4));
    }
    vector<TwoDimensionalVector*> triangleVector;
};


TEST_F(TriangleTest, ConstructorNoException){
    ASSERT_NO_THROW(new Triangle(triangleVector));
}

TEST(Triangle, ExceptionForVectorLessThanThree){
    vector<TwoDimensionalVector*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalVector(3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalVector(0, 4));
    try {
        new Triangle(triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("this is not a triangle!", e);
    }
}

TEST(Triangle, ExceptionForVectorMoreThanThree){
    vector<TwoDimensionalVector*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalVector(3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalVector(0, 4));
    triangleExceptionVector.push_back(new TwoDimensionalVector(-3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalVector(0, -4));
    try {
        new Triangle(triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("this is not a triangle!", e);
    }
}

TEST(Triangle, ExceptionForAreaIsZero){
    vector<TwoDimensionalVector*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalVector(0, 0));
    triangleExceptionVector.push_back(new TwoDimensionalVector(0, 0));
    triangleExceptionVector.push_back(new TwoDimensionalVector(-3, 0));
    try {
        new Triangle(triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("this is not a triangle!", e);
    }
}

TEST_F(TriangleTest, Area){
    Shape* triangle = new Triangle(triangleVector);
    ASSERT_EQ(6, triangle->area());
}

TEST_F(TriangleTest, Perimeter){
    Shape* triangle = new Triangle(triangleVector);
    ASSERT_EQ(12, triangle->perimeter());
}

TEST_F(TriangleTest, Type){
    Shape* triangle = new Triangle(triangleVector);
    ASSERT_EQ("triangle", triangle->type());
}