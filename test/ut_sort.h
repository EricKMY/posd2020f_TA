#include <gtest/gtest.h>
#include <string>
#include <math.h>
#include <vector>
#include <stdio.h>
#include "../src/sort.h"
#include "../src/shape.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/two_dimensional_coordinate.h"

using namespace std;

class QuickSort: public ::testing::Test {
protected:
    virtual void SetUp() {
        vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        _shapes.push_back(new Rectangle(3, 4));
        _shapes.push_back(new Ellipse(4, 3));
        _shapes.push_back(new Triangle(triangleVector));
    }
    vector<Shape*> _shapes;
};

TEST_F(QuickSort, LambdaAreaAscending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    EXPECT_EQ(6, _shapes[0]->area());
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(QuickSort, LambdaAreaDecending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    EXPECT_NEAR(37.699, _shapes[0]->area(), 0.001);
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_EQ(6, _shapes[2]->area());
}

TEST_F(QuickSort, LambdaPerimeterAscending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->perimeter() < b->perimeter(); 
    });

    EXPECT_EQ(12, _shapes[0]->perimeter());
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(QuickSort, LambdaPerimeterDecending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->perimeter() > b->perimeter(); 
    });

    EXPECT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(QuickSort, FunctionAreaAscending) {
    quickSort(_shapes.begin(), _shapes.end(), areaAscendingCompare);

    EXPECT_EQ(6, _shapes[0]->area());
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(QuickSort, FunctionAreaDecending) {
    quickSort(_shapes.begin(), _shapes.end(), areaDescendingCompare);

    EXPECT_NEAR(37.699, _shapes[0]->area(), 0.001);
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_EQ(6, _shapes[2]->area());
}

TEST_F(QuickSort, FunctionPerimeterAscending) {
    quickSort(_shapes.begin(), _shapes.end(), perimeterAscendingCompare);

    EXPECT_EQ(12, _shapes[0]->perimeter());
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(QuickSort, FunctionPerimeterDecending) {
    quickSort(_shapes.begin(), _shapes.end(), perimeterDescendingCompare);

    EXPECT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(QuickSort, ObjectAreaAscending) {
    quickSort(_shapes.begin(), _shapes.end(), AscendingCompare("area"));

    EXPECT_EQ(6, _shapes[0]->area());
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(QuickSort, ObjectAreaDecending) {
    quickSort(_shapes.begin(), _shapes.end(), DescendingCompare("area"));

    EXPECT_NEAR(37.699, _shapes[0]->area(), 0.001);
    EXPECT_EQ(12, _shapes[1]->area());
    EXPECT_EQ(6, _shapes[2]->area());
}

TEST_F(QuickSort, ObjectPerimeterAscending) {
    quickSort(_shapes.begin(), _shapes.end(), AscendingCompare("perimeter"));

    EXPECT_EQ(12, _shapes[0]->perimeter());
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(QuickSort, ObjectPerimeterDecending) {
    quickSort(_shapes.begin(), _shapes.end(), DescendingCompare("perimeter"));

    EXPECT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    EXPECT_EQ(14, _shapes[1]->perimeter());
    EXPECT_EQ(12, _shapes[2]->perimeter());
}