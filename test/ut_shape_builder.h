#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/shape_builder.h"

class Shape;

TEST(ShapeBuilderTest, build_rectangle) {
    ShapeBuilder sb;
    sb.buildRectangle(3, 4);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

TEST(ShapeBuilderTest, build_ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse(4.2, 3.7);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (4.200, 3.700)", results.top()->info());
}

TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());
}

TEST(ShapeBuilderTest, build_multi_simple_shapes) {
    ShapeBuilder sb;
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());

    results.pop();

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

TEST(ShapeBuilderTest, build_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    EXPECT_EQ("Compound Shape {}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_rectangle) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    EXPECT_EQ("Compound Shape {Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_ellipse) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildEllipse(4.2, 3.7);
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Ellipse (4.200, 3.700)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_trinalge) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_multi_simple_shapes) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_multi_simple_shapes_and_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());
}

TEST(ShapeBuilderTest, build_compoundShape_and_multi_shapes_at_same_time) {
    ShapeBuilder sb;

    sb.buildTriangle(0, 0, 0, -3, -4, 0);

    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();

    sb.buildRectangle(3, 4);

    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();

    sb.buildEllipse(4.2, 3.7);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape {}", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());

    results.pop();

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());
}

TEST(ShapeBuilderTest, build_level_3_compoundShape_and_multi_shapes_at_same_time) {
    ShapeBuilder sb;

    sb.buildTriangle(0, 0, 0, -3, -4, 0);

    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeBegin();
    sb.buildEllipse(4.2, 3.7);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();

    sb.buildRectangle(3, 4);

    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();

    sb.buildEllipse(4.2, 3.7);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape {}", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());

    results.pop();

    EXPECT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700)}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.top()->info());

    results.pop();

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());
}
