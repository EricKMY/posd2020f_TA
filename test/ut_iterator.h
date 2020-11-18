#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"

class IteratorTestSuite: public testing::Test {
    protected:
    virtual void SetUp() {

        std::vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse = new Ellipse("1", 4, 3);
        rectangle = new Rectangle("2", 3, 4);
        triangle = new Triangle("3", coordinates);

        shapes.push_back(ellipse);
        shapes.push_back(rectangle);
        shapes.push_back(triangle);

        compoundShape = new CompoundShape("4", shapes);
    }

    virtual void TearDown() {}

    std::list<Shape*> shapes = {};

    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;
    Shape* compoundShape;
};

TEST_F(IteratorTestSuite, exception_for_rectangle_iterate_first){
    Iterator* it = rectangle->createIterator();
    try {
        it->first();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_rectangle_iterate_current_item){
    Iterator* it = rectangle->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_rectangle_iterate_next){
    Iterator* it = rectangle->createIterator();
    try {
        it->next();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, rectangle_iterate_is_done){
    Iterator* it = rectangle->createIterator();
    ASSERT_TRUE(it->isDone());
}


TEST_F(IteratorTestSuite, exception_for_ellipse_iterate_first){
    Iterator* it = ellipse->createIterator();
    try {
        it->first();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_ellipse_iterate_current_item){
    Iterator* it = ellipse->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_ellipse_iterate_next){
    Iterator* it = ellipse->createIterator();
    try {
        it->next();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, ellipse_iterate_is_done){
    Iterator* it = ellipse->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTestSuite, exception_for_triangle_iterate_first){
    Iterator* it = triangle->createIterator();
    try {
        it->first();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_triangle_iterate_current_item){
    Iterator* it = triangle->createIterator();
    try {
        it->currentItem();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, exception_for_triangle_iterate_next){
    Iterator* it = triangle->createIterator();
    try {
        it->next();
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorTestSuite, triangle_iterate_is_done){
    Iterator* it = triangle->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorTestSuite, compound_shape_iterate_first) {
    Iterator* it = compoundShape->createIterator();
    ASSERT_NO_THROW(it->first());
}

TEST_F(IteratorTestSuite, compound_shape_iterate_current_item) {
    Iterator* it = compoundShape->createIterator();

    it->first();

    Shape *shape = it->currentItem();

    EXPECT_EQ("1", shape->id());
    EXPECT_EQ("white", shape->color());
    EXPECT_NEAR(37.699, shape->area(), ABS);
    EXPECT_NEAR(22.849, shape->perimeter(), ABS);
    EXPECT_EQ("Ellipse (4.000, 3.000)", shape->info());
}

TEST_F(IteratorTestSuite, compound_shape_iterate_current_next) {
    Iterator* it = compoundShape->createIterator();
    ASSERT_NO_THROW(it->next());

    Shape *shape = it->currentItem();

    EXPECT_EQ("2", shape->id());
    EXPECT_EQ("white", shape->color());
    EXPECT_NEAR(12, shape->area(), ABS);
    EXPECT_NEAR(14, shape->perimeter(), ABS);
    EXPECT_EQ("Rectangle (3.000, 4.000)", shape->info());

    ASSERT_NO_THROW(it->next());

    shape = it->currentItem();

    EXPECT_EQ("3", shape->id());
    EXPECT_EQ("white", shape->color());
    EXPECT_NEAR(6, shape->area(), ABS);
    EXPECT_NEAR(12, shape->perimeter(), ABS);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(IteratorTestSuite, exception_for_compound_shape_iterate_next_out_of_range) {
    Iterator* it = compoundShape->createIterator();
    ASSERT_NO_THROW(it->next());
    ASSERT_NO_THROW(it->next());
    ASSERT_NO_THROW(it->next());

    try {
        it->next();
        FAIL();
    }catch(std::string e) {
        EXPECT_EQ("Moving past the end!", e);
    }
}

TEST_F(IteratorTestSuite, compound_shape_iterate_is_done) {
    Iterator* it = compoundShape->createIterator();
    ASSERT_NO_THROW(it->next());
    ASSERT_NO_THROW(it->next());
    ASSERT_NO_THROW(it->next());
    EXPECT_TRUE(it->isDone());
}