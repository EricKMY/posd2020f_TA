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
    EXPECT_NEAR(12, results.top()->area(), ABS);
    EXPECT_NEAR(14, results.top()->perimeter(), ABS);
    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

TEST(ShapeBuilderTest, build_ellipse) {
    ShapeBuilder sb;
    sb.buildEllipse("2", 4.2, 3.7);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_NEAR(48.820, results.top()->area(), ABS);
    EXPECT_NEAR(25.247, results.top()->perimeter(), ABS);
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());
}

TEST(ShapeBuilderTest, build_triangle) {
    ShapeBuilder sb;
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);
    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(1, results.size());

    EXPECT_EQ("Triangle", results.top()->type());
    EXPECT_EQ("3", results.top()->id());
    EXPECT_NEAR(6, results.top()->area(), ABS);
    EXPECT_NEAR(12, results.top()->perimeter(), ABS);
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());
}

TEST(ShapeBuilderTest, build_multi_simple_shape) {
    ShapeBuilder sb;
    sb.buildRectangle("1", 3, 4);
    sb.buildEllipse("2", 4.2, 3.7);
    sb.buildTriangle("3", 0, 0, 0, -3, -4, 0);

    std::stack<Shape*> results = sb.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Triangle", results.top()->type());
    EXPECT_EQ("3", results.top()->id());
    EXPECT_NEAR(6, results.top()->area(), ABS);
    EXPECT_NEAR(12, results.top()->perimeter(), ABS);
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.top()->info());

    results.pop();

    EXPECT_EQ("Ellipse", results.top()->type());
    EXPECT_EQ("2", results.top()->id());
    EXPECT_NEAR(48.820, results.top()->area(), ABS);
    EXPECT_NEAR(25.247, results.top()->perimeter(), ABS);
    EXPECT_EQ("Ellipse (4.200, 3.700)", results.top()->info());

    results.pop();

    EXPECT_EQ("Rectangle", results.top()->type());
    EXPECT_EQ("1", results.top()->id());
    EXPECT_NEAR(12, results.top()->area(), ABS);
    EXPECT_NEAR(14, results.top()->perimeter(), ABS);
    EXPECT_EQ("Rectangle (3.000, 4.000)", results.top()->info());
}

// TEST(ShapeBuilderTest, build_empty_compoundShape) {
//     ShapeBuilder sb;
//     sb.buildCompundShape("0");

//     std::stack<Shape*> results = sb.getResult();

//     ASSERT_EQ(1, results.size());

//     EXPECT_EQ("CompuendShape", results.top()->type());
//     EXPECT_EQ("0", results.top()->id());
//     EXPECT_NEAR(0, results.top()->area(), ABS);
//     EXPECT_NEAR(0, results.top()->perimeter(), ABS);
//     EXPECT_EQ("CompuendShape {}", results.top()->info());

// }