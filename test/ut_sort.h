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
        _sort = new Sort(&_shapes);
    }
    vector<Shape*> _shapes;
    Sort* _sort;
};

TEST_F(SortTest, StandardSortLambdaAreaAscending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortLambdaAreaDecending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, StandardSortLambdaPerimeterAscending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->perimeter() < b->perimeter(); 
    });

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortLambdaPerimeterDecending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->perimeter() > b->perimeter(); 
    });

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, StandardSortFuncAreaAscending) {
    _sort->standardSort(areaAscendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortFuncAreaDecending) {
    _sort->standardSort(areaDescendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, StandardSortFuncPerimeterAscending) {
    _sort->standardSort(perimeterAscendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortFuncPerimeterDecending) {
    _sort->standardSort(perimeterDescendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, StandardSortObjAreaAscending) {
    ASSERT_NO_THROW(AscendingCompare("area"));
    AscendingCompare ascendingCompare("area");
    _sort->standardSort(ascendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortObjAreaDecending) {
    ASSERT_NO_THROW(DescendingCompare("area"));
    DescendingCompare descendingCompare("area");
    _sort->standardSort(descendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, StandardSortObjPerimeterAscending) {
    ASSERT_NO_THROW(AscendingCompare("perimeter"));
    AscendingCompare ascendingCompare("perimeter");
    _sort->standardSort(ascendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortObjPerimeterDecending) {
    ASSERT_NO_THROW(DescendingCompare("perimeter"));
    DescendingCompare descendingCompare("perimeter");
    _sort->standardSort(descendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}


TEST_F(SortTest, QuickSortLambdaAreaAscending) {
    _sort->quickSort([](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortLambdaAreaDecending) {
    _sort->quickSort([](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortLambdaPerimeterAscending) {
    _sort->quickSort([](Shape* a, Shape* b) {
        return a->perimeter() < b->perimeter(); 
    });

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortLambdaPerimeterDecending) {
    _sort->quickSort([](Shape* a, Shape* b) {
        return a->perimeter() > b->perimeter(); 
    });

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, QuickSortFuncAreaAscending) {
    _sort->quickSort(areaAscendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortFuncAreaDecending) {
    _sort->quickSort(areaDescendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortFuncPerimeterAscending) {
    _sort->quickSort(perimeterAscendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortFuncPerimeterDecending) {
    _sort->quickSort(perimeterDescendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}

TEST_F(SortTest, QuickSortObjAreaAscending) {
    ASSERT_NO_THROW(AscendingCompare("area"));
    AscendingCompare ascendingCompare("area");
    _sort->quickSort(ascendingCompare);

    ASSERT_EQ(6, _shapes[0]->area());
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_NEAR(37.699, _shapes[2]->area(), 0.001);
}

TEST_F(SortTest, QuickSortObjAreaDecending) {
    ASSERT_NO_THROW(DescendingCompare("area"));
    DescendingCompare descendingCompare("area");
    _sort->quickSort(descendingCompare);

    ASSERT_NEAR(37.699, _shapes[0]->area(), 0.001);
    ASSERT_EQ(12, _shapes[1]->area());
    ASSERT_EQ(6, _shapes[2]->area());
}

TEST_F(SortTest, QuickSortObjPerimeterAscending) {
    ASSERT_NO_THROW(AscendingCompare("perimeter"));
    AscendingCompare ascendingCompare("perimeter");
    _sort->quickSort(ascendingCompare);

    ASSERT_EQ(12, _shapes[0]->perimeter());
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_NEAR(22.849, _shapes[2]->perimeter(), 0.001);
}

TEST_F(SortTest, QuickSortObjPerimeterDecending) {
    ASSERT_NO_THROW(DescendingCompare("perimeter"));
    DescendingCompare descendingCompare("perimeter");
    _sort->quickSort(descendingCompare);

    ASSERT_NEAR(22.849, _shapes[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapes[1]->perimeter());
    ASSERT_EQ(12, _shapes[2]->perimeter());
}