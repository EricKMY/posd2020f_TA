// #include <string>
// #include "../src/scanner.h"



// TEST(Scanner, BRACE_TOKEN) {
//     std::string input = "{\n}";
//      Scanner *scn = new Scanner(input);
//     ASSERT_EQ("{", scn->nextToken());
//     ASSERT_EQ("}", scn->nextToken());
// } 


// TEST(Scanner, CompoundShape) {
//     std::string input = "CompoundShape {Ellipse ([-1.000, 3.140], 4.000, 3.000), Rectangle ([0.000, 0.000], [-3.000, 0.000], [-3.000, -4.000], [0.000, -4.000]), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}";
//     Scanner *scn = new Scanner(input);

//     ASSERT_EQ("CompoundShape", scn->nextToken());
//     ASSERT_EQ("{", scn->nextToken());
//     ASSERT_EQ("Ellipse", scn->nextToken());
//     ASSERT_EQ("Rectangle", scn->nextToken());
//     ASSERT_EQ("Triangle", scn->nextToken());
//     ASSERT_EQ("}", scn->nextToken());

//     try {
//         scn->nextToken();
//         FAIL();
//     }catch(std::string s) {
//         ASSERT_EQ("next char doesn't exist.", s);
//     }
// } 