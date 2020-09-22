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

class SortTest: public testing::Test {
protected:
    virtual void SetUp(){
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

TEST_F(SortTest, QuickSortLambdaAreaAscending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortLambdaAreaDecending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortLambdaPerimeterAscending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->perimeter() < b->perimeter(); 
    });

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortLambdaPerimeterDecending) {
    quickSort(_shapes.begin(), _shapes.end(), [](Shape* a, Shape* b) {
        return a->perimeter() > b->perimeter(); 
    });

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, QuickSortFuncAreaAscending) {
    quickSort(_shapes.begin(), _shapes.end(), areaAscendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortFuncAreaDecending) {
    quickSort(_shapes.begin(), _shapes.end(), areaDescendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortFuncPerimeterAscending) {
    quickSort(_shapes.begin(), _shapes.end(), perimeterAscendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortFuncPerimeterDecending) {
    quickSort(_shapes.begin(), _shapes.end(), perimeterDescendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, QuickSortObjAreaAscending) {
    ASSERT_NO_THROW(AscendingCompare("area"));
    AscendingCompare ascendingCompare("area");
    quickSort(_shapes.begin(), _shapes.end(), ascendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortObjAreaDecending) {
    ASSERT_NO_THROW(DescendingCompare("area"));
    DescendingCompare descendingCompare("area");
    quickSort(_shapes.begin(), _shapes.end(), descendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortObjPerimeterAscending) {
    ASSERT_NO_THROW(AscendingCompare("perimeter"));
    AscendingCompare ascendingCompare("perimeter");
    quickSort(_shapes.begin(), _shapes.end(), ascendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortObjPerimeterDecending) {
    ASSERT_NO_THROW(DescendingCompare("perimeter"));
    DescendingCompare descendingCompare("perimeter");
    quickSort(_shapes.begin(), _shapes.end(), descendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}