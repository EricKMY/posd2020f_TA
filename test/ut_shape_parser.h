#include <string>
#include "../src/shape_parser.h"

TEST(ShapeParser, parser_ellipse) {
    std::string input = "Ellipse (4.000, 3.000)";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("Ellipse 4 3\n", sp->getResult()[0]);
}

TEST(ShapeParser, parser_rectangle) {
    std::string input = "Rectangle (3.000, 4.000)";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("Rectangle 3 4\n", sp->getResult()[0]);
}

TEST(ShapeParser, parser_triangle) {
    std::string input = "Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("Triangle 0 0 3 0 0 4\n", sp->getResult()[0]);
}

TEST(ShapeParser, parser_compound_shape_contains_ellipse) {
    std::string input = "CompoundShape {Ellipse (4.000, 3.000)}";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("CompoundShape {\n", sp->getResult()[0]);
    ASSERT_EQ("Ellipse 4 3\n", sp->getResult()[1]);
    ASSERT_EQ("}\n", sp->getResult()[2]);
} 

TEST(ShapeParser, parser_compound_shape_contains_rectangle) {
    std::string input = "CompoundShape {Rectangle (3.000, 4.000)}";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("CompoundShape {\n", sp->getResult()[0]);
    ASSERT_EQ("Rectangle 3 4\n", sp->getResult()[1]);
    ASSERT_EQ("}\n", sp->getResult()[2]);
} 

TEST(ShapeParser, parser_compound_shape_contains_triangle) {
    std::string input = "CompoundShape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("CompoundShape {\n", sp->getResult()[0]);
    ASSERT_EQ("Triangle 0 0 3 0 0 4\n", sp->getResult()[1]);
    ASSERT_EQ("}\n", sp->getResult()[2]);
} 


TEST(ShapeParser, parser_compound_shape_contains_compound_shape) {
    std::string input = "CompoundShape {Rectangle (3.000, 4.000), CompoundShape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}}";
    ShapeParser *sp = new ShapeParser(input);
    sp->parser();
    ASSERT_EQ("CompoundShape {\n", sp->getResult()[0]);
    ASSERT_EQ("Rectangle 3 4\n", sp->getResult()[1]);
    ASSERT_EQ("CompoundShape {\n", sp->getResult()[2]);
    ASSERT_EQ("Ellipse 4 3\n", sp->getResult()[3]);
    ASSERT_EQ("Rectangle 3 4\n", sp->getResult()[4]);
    ASSERT_EQ("Triangle 0 0 3 0 0 4\n", sp->getResult()[5]);
    ASSERT_EQ("}\n", sp->getResult()[6]);
    ASSERT_EQ("}\n", sp->getResult()[7]);
} 
