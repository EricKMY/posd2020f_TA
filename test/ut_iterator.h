#include <gtest/gtest.h>
#include <vector>
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

class IteratorTest: public testing::Test {
    protected:
    virtual void SetUp() {

        vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse = new Ellipse("1", 4, 3);
        rectangle = new Rectangle("2", 3, 4);
        triangle = new Triangle("3", coordinates);

        shapes->push_back(ellipse);
        shapes->push_back(rectangle);
        shapes->push_back(triangle);

        compoundShape = new CompoundShape("4", shapes);
    }

    virtual void TearDown() {
        shapes->clear();
        delete ellipse;
        delete rectangle;
        delete triangle;
    }

    vector<Shape*> *shapes = new vector<Shape*>();

    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;
    Shape* compoundShape;
};

TEST_F(IteratorTest, ExceptionForRectangleIterateFirst){
    Iterator *it = rectangle->createIterator();
    try {
        it->first();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForRectangleIterateCurrentItem){
    Iterator *it = rectangle->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForRectangleIterateNext){
    Iterator *it = rectangle->createIterator();
    try {
        it->next();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, RectangleIterateIsDone){
    Iterator *it = rectangle->createIterator();
    ASSERT_TRUE(it->isDone());
}


TEST_F(IteratorTest, ExceptionForEllipseIterateFirst){
    Iterator *it = ellipse->createIterator();
    try {
        it->first();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForEllipseIterateCurrentItem){
    Iterator *it = ellipse->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForEllipseIterateNext){
    Iterator *it = ellipse->createIterator();
    try {
        it->next();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, EllipseIterateIsDone){
    Iterator *it = ellipse->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTest, ExceptionForTriangleIterateFirst){
    Iterator *it = triangle->createIterator();
    try {
        it->first();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForTriangleIterateCurrentItem){
    Iterator *it = triangle->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, ExceptionForTriangleIterateNext){
    Iterator *it = triangle->createIterator();
    try {
        it->next();
        FAIL();
    }catch(string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTest, TriangleIterateIsDone){
    Iterator *it = triangle->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTest, CompoundShapeIterateFirst) {
    Iterator *it = compoundShape->createIterator();
    ASSERT_NO_THROW(it->first());
}

TEST_F(IteratorTest, CompoundShapeIterateCurrentItem) {
    Iterator *it = compoundShape->createIterator();

    it->first();

    Shape *shape = it->currentItem();

    EXPECT_EQ("1", shape->id());
    EXPECT_EQ("White", shape->color());
    EXPECT_NEAR(37.699, shape->area(), 0.001);
    EXPECT_NEAR(22.849, shape->perimeter(), 0.001);
    EXPECT_EQ("Ellipse (4.000, 3.000)", shape->info());
}

TEST_F(IteratorTest, CompoundShapeIterateNext) {
    Iterator *it = compoundShape->createIterator();

    it->first();
    EXPECT_NO_THROW(it->next());

    Shape *shape = it->currentItem();

    EXPECT_EQ("2", shape->id());
    EXPECT_EQ("White", shape->color());
    EXPECT_NEAR(12, shape->area(), 0.001);
    EXPECT_NEAR(14, shape->perimeter(), 0.001);
    EXPECT_EQ("Rectangle (3.000, 4.000)", shape->info());

    EXPECT_NO_THROW(it->next());

    shape = it->currentItem();

    EXPECT_EQ("3", shape->id());
    EXPECT_EQ("White", shape->color());
    EXPECT_NEAR(6, shape->area(), 0.001);
    EXPECT_NEAR(12, shape->perimeter(), 0.001);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(IteratorTest, ExceptionForCompoundShapeIterateNextOutOfRange) {
    Iterator *it = compoundShape->createIterator();
    it->first();
    EXPECT_NO_THROW(it->next());
    EXPECT_NO_THROW(it->next());
    EXPECT_NO_THROW(it->next());

    try {
        it->next();
        FAIL();
    }catch(string e) {
        EXPECT_EQ("Moving past the end!", e);
    }
}

TEST_F(IteratorTest, CompoundShapeIterateIsDone) {
    Iterator *it = compoundShape->createIterator();
    it->first();
    EXPECT_NO_THROW(it->next());
    EXPECT_NO_THROW(it->next());
    EXPECT_NO_THROW(it->next());
    EXPECT_TRUE(it->isDone());
}