#include "../src/triangle.h"
#include "../src/two_dimensional_coordinate.h"

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
    ASSERT_NO_THROW(new Triangle(triangleVector));
}

TEST(Triangle, ExceptionForVectorLessThanThree){
    vector<TwoDimensionalCoordinate*> triangleExceptionVector;
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(0, 4));
    try {
        new Triangle(triangleExceptionVector);
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
        new Triangle(triangleExceptionVector);
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
        new Triangle(triangleExceptionVector);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a triangle!", e);
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
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle->info());
}