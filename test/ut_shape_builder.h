#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/shape_builder.h"

class Shape;

TEST(ShapeBuilderTest, build_rectangle) {
    ShapeBuilder sb;
    sb.buildRectangle("1", 3, 4);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Rectangle", results.top()->type());
    EXPECT_EQ("1", results.top()->id());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

TEST(ShapeBuilderTest, build_ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse("2", 4.2, 3.7);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());
}

TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Triangle", results.top()->type());
    EXPECT_EQ("3", results.top()->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());
}

TEST(ShapeBuilderTest, build_multi_simple_shapes) {
    ShapeBuilder sb;
    sb.buildRectangle("1", 3, 4);
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Triangle", results.top()->type());
    EXPECT_EQ("3", results.top()->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());

    results.pop();

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle", results.top()->type());
    EXPECT_EQ("1", results.top()->id());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

// TEST(ShapeBuilderTest, build_empty_compoundShape) {
    // ShapeBuilder sb;
    // sb.buildCompundShapeStart("0");
    // sb.buildCompundShapeEnd();

    // std::stack<Shape*> results = sb.getResult();

    // ASSERT_EQ(1, results.size());

    // EXPECT_EQ("Compound Shape", results.top()->type());
    // EXPECT_EQ("0", results.top()->id());
    // EXPECT_EQ("Compound Shape {}", results.top()->info());

// }

TEST(ShapeBuilderTest, build_compoundShape_that_contains_rectangle) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildRectangle("1", 3, 4);
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_ellipse) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Ellipse (4.200, 3.700)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_trinalge) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_multi_simple_shapes) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildRectangle("1", 3, 4);
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildCompundShapeStart();
    sb.buildCompundShapeEnd("0");
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Compound Shape{}}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_multi_simple_shapes_and_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompundShapeStart();
    sb.buildRectangle("1", 3, 4);
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    sb.buildCompundShapeStart();
    sb.buildCompundShapeEnd("0");
    sb.buildCompundShapeEnd("4");

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Compound Shape{}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_level_1_compoundShape_and_multi_shapes_at_same_time) {
    ShapeBuilder sb;

    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);

    sb.buildCompundShapeStart();
    sb.buildRectangle("1", 3, 4);
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    sb.buildCompundShapeEnd("4");

    sb.buildRectangle("1", 3, 4);

    sb.buildCompundShapeStart();
    sb.buildCompundShapeEnd("0");

    sb.buildEllipse("2", 4.2, 3.7);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("0", results.top()->id());
    EXPECT_EQ("Compound Shape {}", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle", results.top()->type());
    EXPECT_EQ("1", results.top()->id());
    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape", results.top()->type());
    EXPECT_EQ("4", results.top()->id());
    EXPECT_EQ("Compound Shape {Compound Shape{}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());

    results.pop();

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());
}