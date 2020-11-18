#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/utility.h"

class UtlilityTestSuite: public testing::Test {
    protected:
    virtual void SetUp() {

        ellipse_1 = new Ellipse("1", 4.2, 3.7, "red");
        rectangle_2 = new Rectangle("2", 2, 2, "blue");

        std::vector<TwoDimensionalCoordinate*> triangle_3_coordinates;
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(0, -3));
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(-4, 0));
        triangle_3 = new Triangle("3", triangle_3_coordinates, "yellow");

        ellipse_4 = new Ellipse("4", 4.2, 3.7, "yellow");
        rectangle_5 = new Rectangle("5", 2, 2, "blue");

        std::vector<TwoDimensionalCoordinate*> triangle_6_coordinates;
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(0, -3));
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(-4, 0));
        triangle_6 = new Triangle("6", triangle_6_coordinates, "red");

        std::list<Shape*> shapes = {};
        shapes.push_back(ellipse_1);
        shapes.push_back(rectangle_2);
        shapes.push_back(triangle_3);
        compoundShape_7 = new CompoundShape("7", shapes);

        shapes.clear();
        shapes.push_back(ellipse_4);
        compoundShape_8 = new CompoundShape("8", shapes);

        shapes.clear();
        shapes.push_back(rectangle_5);
        shapes.push_back(triangle_6);
        compoundShape_9 = new CompoundShape("9", shapes);

        compoundShape_8->addShape(compoundShape_9);
        compoundShape_7->addShape(compoundShape_8);
    }

    virtual void TearDown() {}

    Shape* ellipse_1;
    Shape* rectangle_2;
    Shape* triangle_3;
    Shape* ellipse_4;
    Shape* rectangle_5;
    Shape* triangle_6;
    Shape* compoundShape_7;
    Shape* compoundShape_8;
    Shape* compoundShape_9;
};

TEST_F(UtlilityTestSuite, exception_for_rectangle_get_shape_by_id) {
    try {
        getShapeById(rectangle_2, "1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTestSuite, exception_for_rectangle_filter_shape) {
    try {
        filterShape(rectangle_2, AreaFilter(12, 1));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can filter shape!", e);
    }
}

TEST_F(UtlilityTestSuite, exception_for_ellipse_get_shape_by_id) {
    try {
        getShapeById(ellipse_1, "1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTestSuite, exception_for_ellipse_filter_shape) {
    try {
        filterShape(rectangle_2, AreaFilter(12, 1));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can filter shape!", e);
    }
}

TEST_F(UtlilityTestSuite, exception_for_triangle_get_shape_by_id) {
    try {
        getShapeById(triangle_3, "1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTestSuite, exception_for_triangle_filter_shape) {
    try {
        filterShape(triangle_3, ColorFilter("Yellow"));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can filter shape!", e);
    }
}

TEST_F(UtlilityTestSuite, compound_shape_get_shape_by_id) {
    Shape *shape = getShapeById(compoundShape_7, "1");

    EXPECT_EQ("1", shape->id());
    EXPECT_EQ("red", shape->color());
    EXPECT_NEAR(48.820, shape->area(), ABS);
    EXPECT_NEAR(25.247, shape->perimeter(), ABS);
    EXPECT_EQ("Ellipse (4.200, 3.700)", shape->info());

    shape = getShapeById(compoundShape_7, "2");
    
    EXPECT_EQ("2", shape->id());
    EXPECT_EQ("blue", shape->color());
    EXPECT_NEAR(4, shape->area(), ABS);
    EXPECT_NEAR(8, shape->perimeter(), ABS);
    EXPECT_EQ("Rectangle (2.000, 2.000)", shape->info());

    shape = getShapeById(compoundShape_7, "3");

    EXPECT_EQ("3", shape->id());
    EXPECT_EQ("yellow", shape->color());
    EXPECT_NEAR(6, shape->area(), ABS);
    EXPECT_NEAR(12, shape->perimeter(), ABS);
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", shape->info());
}

TEST_F(UtlilityTestSuite, compound_shape_filter_shape_by_area) {

    std::deque<Shape*> results = filterShape(compoundShape_7, AreaFilter(20, 5));

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("3", results[0]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
    EXPECT_NEAR(6, results[0]->area(), ABS);

    EXPECT_EQ("9", results[1]->id());
    EXPECT_EQ("Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results[1]->info());
    EXPECT_NEAR(10, results[1]->area(), ABS);
    
    EXPECT_EQ("6", results[2]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
    EXPECT_NEAR(6, results[2]->area(), ABS);
}

TEST_F(UtlilityTestSuite, compound_shape_filter_shape_by_perimeter) {
    std::deque<Shape*> results = filterShape(compoundShape_7, PerimeterFilter(30, 15));

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("1", results[0]->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[0]->info());
    EXPECT_NEAR(25.247, results[0]->perimeter(), ABS);

    EXPECT_EQ("4", results[1]->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_NEAR(25.247, results[1]->perimeter(), ABS);

    EXPECT_EQ("9", results[2]->id());
    EXPECT_EQ("Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results[2]->info());
    EXPECT_NEAR(20, results[2]->perimeter(), ABS);
}

TEST_F(UtlilityTestSuite, compound_shape_filter_shape_by_type) {
    std::deque<Shape*> results = filterShape(compoundShape_7, TypeFilter("Rectangle"));

    ASSERT_EQ(2, results.size());

    EXPECT_EQ("2", results[0]->id());
    EXPECT_EQ("Rectangle (2.000, 2.000)", results[0]->info());

    EXPECT_EQ("5", results[1]->id());
    EXPECT_EQ("Rectangle (2.000, 2.000)", results[1]->info());
}

TEST_F(UtlilityTestSuite, compound_shape_filter_shape_by_color) {

    std::deque<Shape*> results = filterShape(compoundShape_7, ColorFilter("red"));

    ASSERT_EQ(2, results.size());

    EXPECT_EQ("1", results[0]->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[0]->info());
    EXPECT_EQ("red", results[0]->color());

    EXPECT_EQ("6", results[1]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[1]->info());
    EXPECT_EQ("red", results[1]->color());
}