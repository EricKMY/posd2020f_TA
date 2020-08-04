#ifndef UT_TWO_DIMENSIONAL_VECTOR_H
#define UT_TWO_DIMENSIONAL_VECTOR_H

#include "../src/two_dimensional_vector.h"

TEST(TwoDimensionalVector, getXAndY){
    TwoDimensionalVector* v = new TwoDimensionalVector(3, 4);
    ASSERT_EQ(3, v->getX());
    ASSERT_EQ(4, v->getY());
}

TEST(TwoDimensionalVector, getLength){
    TwoDimensionalVector* v = new TwoDimensionalVector(3, 4);
    ASSERT_EQ(5, v->length());
}

TEST(TwoDimensionalVector, dotCalculation){
    TwoDimensionalVector* v1 = new TwoDimensionalVector(3, 4);
    TwoDimensionalVector* v2 = new TwoDimensionalVector(6, 6);

    ASSERT_EQ(42, v1->dot(v2));
    ASSERT_EQ(42, v2->dot(v1));
}


TEST(TwoDimensionalVector, crossCalculation){
    TwoDimensionalVector* v1 = new TwoDimensionalVector(3, 4);
    TwoDimensionalVector* v2 = new TwoDimensionalVector(-3, 4);

    ASSERT_EQ(24, v1->cross(v2));
    ASSERT_EQ(-24, v2->cross(v1));
}

TEST(TwoDimensionalVector, subtractCalculation){
    TwoDimensionalVector* v1 = new TwoDimensionalVector(3, 4);
    TwoDimensionalVector* v2 = new TwoDimensionalVector(-3, 4);
    ASSERT_EQ(6, v1->subtract(v2)->length());
    ASSERT_EQ(6, v1->subtract(v2)->getX());
    ASSERT_EQ(0, v1->subtract(v2)->getY());

    ASSERT_EQ(6, v2->subtract(v1)->length());
    ASSERT_EQ(-6, v2->subtract(v1)->getX());
    ASSERT_EQ(0, v2->subtract(v1)->getY());
}

#endif