#include "../src/convex_polygon.h"


TEST(ConvexPolygonTest, NoException){
    vector<TwoDimensionalVector*> convexPolygonVectors;
    convexPolygonVectors.push_back(new TwoDimensionalVector(-4, 0));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-3, -2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(2, 2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-2, 1));
    ASSERT_NO_THROW(new Triangle(triangleVector));
}

TEST(ConvexPolygonTest, ExceptionForVectorLessThanFour){
    vector<TwoDimensionalVector*> convexPolygonVectors;
    convexPolygonVectors.push_back(new TwoDimensionalVector(3, 0));
    convexPolygonVectors.push_back(new TwoDimensionalVector(0, 4));
    convexPolygonVectors.push_back(new TwoDimensionalVector(0, 0));
    try {
        new ConvexPolygon(convexPolygonVectors);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("this is not a convexpolygon!", e);
    }
}

TEST(ConvexPolygonTest, ExceptionForAngleMoreThan180){
    vector<TwoDimensionalVector*> convexPolygonVectors;
    convexPolygonVectors.push_back(new TwoDimensionalVector(0, 0));
    convexPolygonVectors.push_back(new TwoDimensionalVector(1, 1));
    convexPolygonVectors.push_back(new TwoDimensionalVector(1, -1));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-1, -1));
    try {
        new ConvexPolygon(convexPolygonVectors);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("this is not a convexpolygon!", e);
    }
}

TEST(ConvexPolygonTest, Area){
    Shape* convexPolygon = new ConvexPolygon(triangleVector);
    vector<TwoDimensionalVector*> convexPolygonVectors;
    convexPolygonVectors.push_back(new TwoDimensionalVector(-4, 0));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-3, -2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(2, 2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-2, 1));
    ASSERT_NEAR(6, convexPolygon->area(), 0.0001);
}

TEST(ConvexPolygonTest, Perimeter){
    Shape* convexPolygon = new ConvexPolygon(triangleVector);
    vector<TwoDimensionalVector*> convexPolygonVectors;
    convexPolygonVectors.push_back(new TwoDimensionalVector(-4, 0));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-3, -2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(2, 2));
    convexPolygonVectors.push_back(new TwoDimensionalVector(-2, 1));
    ASSERT_NEAR(12, convexPolygon->perimeter(), 0.0001);
}

TEST(ConvexPolygonTest, Type){
    Shape* triangle = new Triangle(triangleVector);
    ASSERT_EQ("triangle", triangle->type());
}