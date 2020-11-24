#include <gtest/gtest.h>
#include "../src/shape_parser.h"

TEST(ShapeParserTest, parser_triangle) {
    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());
}

TEST(ShapeParserTest, parser_rectangle) {
    ShapeParser sp("Rectangle (3.000, 4.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results.front()->info());
}

TEST(ShapeParserTest, parser_ellipse) {
    ShapeParser sp("Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (4.200, 3.700)", results.front()->info());
}

TEST(ShapeParserTest, parser_multi_simple_shapes) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.front()->info());
}

TEST(ShapeParserTest, parser_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.front()->info());
}

TEST(ShapeParserTest, parser_empty_compoundShape) {
    ShapeParser sp("CompoundShape {}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_rectangle) {
    ShapeParser sp("CompoundShape {Rectangle (3.000, 4.000)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000)}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_ellipse) {
    ShapeParser sp("CompoundShape {Ellipse (4.200, 3.700)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Ellipse (4.200, 3.700)}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_trinalge) {
    ShapeParser sp("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_multi_simple_shapes) {
    ShapeParser sp("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {
    ShapeParser sp("CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000), Triangle (-3.000, -4.000, 0.000)}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeParser sp("CompoundShape {CompoundShape {}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_multi_simple_shapes_and_a_empty_compoundShape) {
    ShapeParser sp("CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {}}");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_and_multi_shapes_at_same_time) {

    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}, Rectangle (3.000, 4.000), CompoundShape {}, Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());
}

TEST(ShapeParserTest, parser_compoundShape_and_multi_shapes_at_same_time_with_some_shapes_contains_invalid_argument_that_should_be_ignored) {

    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), Rectangle (12.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}, Rectangle (3.000, 4.000), CompoundShape {Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000, 12.000)}, Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());
}

TEST(ShapeParserTest, parser_level_3_compoundShape_and_multi_shapes_at_same_time) {

    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000), CompoundShape {Ellipse (4.200, 3.700), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}}, Rectangle (3.000, 4.000), CompoundShape {}, Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape*> results = sp.getResult();

    ASSERT_EQ(5, results.size());

    EXPECT_EQ("Ellipse (4.200, 3.700)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Rectangle (3.000, 4.000)", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700)}, Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000]), Ellipse (4.200, 3.700), Rectangle (3.000, 4.000)}", results.front()->info());

    results.pop_front();

    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results.front()->info());
}