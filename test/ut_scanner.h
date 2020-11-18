#include <string>
#include "../src/scanner.h"

TEST(Scanner, ellipse) {
    std::string input = "Ellipse (4.000, 3.000)";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("Ellipse", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    try {
        scn->nextToken();
        FAIL();
    }catch(std::string s) {
        ASSERT_EQ("next char doesn't exist.", s);
    }
} 

TEST(Scanner, rectangle) {
    std::string input = "Rectangle (3.000, 4.000)";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("Rectangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
} 

TEST(Scanner, triangle) {
    std::string input = "Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("Triangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
} 

TEST(Scanner, next_token_exception) {
    std::string input = "Rectangle (3.000, 4.000)";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("Rectangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    try {
        scn->nextToken();
        FAIL();
    }catch(std::string s) {
        ASSERT_EQ("next char doesn't exist.", s);
    }
} 


TEST(Scanner, compound_shape_contains_ellipse) {
    std::string input = "CompoundShape {Ellipse (4.000, 3.000)}";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("CompoundShape", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("Ellipse", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());
    
    ASSERT_EQ("}", scn->nextToken());
} 

TEST(Scanner, compound_shape_contains_rectangle) {
    std::string input = "CompoundShape {Rectangle (3.000, 4.000)}";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("CompoundShape", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("Rectangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());
} 

TEST(Scanner, compound_shape_contains_triangle) {
    std::string input = "CompoundShape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("CompoundShape", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("Triangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());
} 


TEST(Scanner, compound_shape_contains_compound_shape) {
    std::string input = "CompoundShape {Rectangle (3.000, 4.000), CompoundShape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}}";
    Scanner *scn = new Scanner(input);

    ASSERT_EQ("CompoundShape", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("Rectangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("CompoundShape", scn->nextToken());
    ASSERT_EQ("{", scn->nextToken());

    ASSERT_EQ("Ellipse", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("Rectangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ(",", scn->nextToken());

    ASSERT_EQ("Triangle", scn->nextToken());
    ASSERT_EQ("(", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("3.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("[", scn->nextToken());
    ASSERT_EQ("0.000", scn->nextToken());
    ASSERT_EQ(",", scn->nextToken());
    ASSERT_EQ("4.000", scn->nextToken());
    ASSERT_EQ("]", scn->nextToken());
    ASSERT_EQ(")", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());

    ASSERT_EQ("}", scn->nextToken());
} 