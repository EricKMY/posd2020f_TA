#ifndef UT_SORT_H
#define UT_SORT_H

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
#include "../src/two_dimensional_vector.h"

class SortTest: public testing::Test {
protected:
    virtual void SetUp(){
        _rectangle = new Rectangle(3, 4);
        _ellipse = new Ellipse(3, 4);
        vector<TwoDimensionalVector*> triangleVector;
        triangleVector.push_back(new TwoDimensionalVector(0, 0));
        triangleVector.push_back(new TwoDimensionalVector(3, 0));
        triangleVector.push_back(new TwoDimensionalVector(0, 4));
        _triangle = new Triangle(triangleVector);
        Shape* _shapeArray[3] = {_triangle, _rectangle, _ellipse};
        _shapeVector.assign(_shapeArray, _shapeArray+3);
        _sort = new Sort(&_shapeVector);
    }
    Shape* _rectangle;
    Shape* _ellipse;
    Shape* _triangle;
    vector<Shape*> _shapeVector;
    Sort* _sort;
};

TEST_F(SortTest, StandardSortLambdaAreaAscending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortLambdaAreaDecending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, StandardSortLambdaPerimeterAscending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() < b->perimeter(); 
    });

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortLambdaPerimeterDecending) {
    _sort->standardSort([](Shape* a, Shape* b) {
        return a->area() > b->perimeter(); 
    });

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}

TEST_F(SortTest, StandardSortFuncAreaAscending) {
    _sort->standardSort(areaAscendingCompare);

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortFuncAreaDecending) {
    _sort->standardSort(areaDecendingCompare);

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, StandardSortFuncPerimeterAscending) {
    _sort->standardSort(areaDecendingCompare);

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortFuncPerimeterDecending) {
    _sort->standardSort(areaDecendingCompare);

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}

TEST_F(SortTest, StandardSortObjAreaAscending) {
    ASSERT_NO_THROW(AscendingCompare("area"));
    AscendingCompare ascendingCompare("area");
    _sort->standardSort(ascendingCompare);

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, StandardSortObjAreaDecending) {
    ASSERT_NO_THROW(DecendingCompare("area"));
    DecendingCompare decendingCompare("area");
    _sort->standardSort(decendingCompare);

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, StandardSortObjPerimeterAscending) {
    ASSERT_NO_THROW(AscendingCompare("perimeter"));
    AscendingCompare ascendingCompare("perimeter");
    _sort->standardSort(ascendingCompare);

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, StandardSortObjPerimeterDecending) {
    ASSERT_NO_THROW(DecendingCompare("perimeter"));
    DecendingCompare decendingCompare("perimeter");
    _sort->standardSort(decendingCompare);

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}


TEST_F(SortTest, CustomSortLambdaAreaAscending) {
    _sort->customizeSort([](Shape* a, Shape* b) {
        return a->area() < b->area(); 
    });

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, CustomdSortLambdaAreaDecending) {
    _sort->customizeSort([](Shape* a, Shape* b) {
        return a->area() > b->area(); 
    });

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, CustomSortLambdaPerimeterAscending) {
    _sort->customizeSort([](Shape* a, Shape* b) {
        return a->area() < b->perimeter(); 
    });

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, CustomSortLambdaPerimeterDecending) {
    _sort->customizeSort([](Shape* a, Shape* b) {
        return a->area() > b->perimeter(); 
    });

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}

TEST_F(SortTest, CustomSortFuncAreaAscending) {
    _sort->customizeSort(areaAscendingCompare);

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, CustomSortFuncAreaDecending) {
    _sort->customizeSort(areaDecendingCompare);

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, CustomSortFuncPerimeterAscending) {
    _sort->customizeSort(areaDecendingCompare);

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, CustomSortFuncPerimeterDecending) {
    _sort->customizeSort(areaDecendingCompare);

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}

TEST_F(SortTest, CustomSortObjAreaAscending) {
    ASSERT_NO_THROW(AscendingCompare("area"));
    AscendingCompare ascendingCompare("area");
    _sort->customizeSort(ascendingCompare);

    ASSERT_EQ(6, _shapeVector[0]->area());
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_NEAR(21.132, _shapeVector[2]->area(), 0.001);
}

TEST_F(SortTest, CustomSortObjAreaDecending) {
    ASSERT_NO_THROW(DecendingCompare("area"));
    DecendingCompare decendingCompare("area");
    _sort->customizeSort(decendingCompare);

    ASSERT_NEAR(21.132, _shapeVector[0]->area(), 0.001);
    ASSERT_EQ(12, _shapeVector[1]->area());
    ASSERT_EQ(6, _shapeVector[2]->area());
}

TEST_F(SortTest, CustomSortObjPerimeterAscending) {
    ASSERT_NO_THROW(AscendingCompare("perimeter"));
    AscendingCompare ascendingCompare("perimeter");
    _sort->customizeSort(ascendingCompare);

    ASSERT_EQ(12, _shapeVector[0]->perimeter());
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_NEAR(37.699, _shapeVector[1]->perimeter(), 0.001);
}

TEST_F(SortTest, CustomSortObjPerimeterDecending) {
    ASSERT_NO_THROW(DecendingCompare("perimeter"));
    DecendingCompare decendingCompare("perimeter");
    _sort->customizeSort(decendingCompare);

    ASSERT_NEAR(37.699, _shapeVector[0]->perimeter(), 0.001);
    ASSERT_EQ(14, _shapeVector[1]->perimeter());
    ASSERT_EQ(12, _shapeVector[2]->perimeter());
}

#endif