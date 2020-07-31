#include "../src/rectangle.h"



// TEST(Rectangle, ConstructorNoException){
//     ASSERT_NO_THROW(Rectangle(1, 1));
// }

// TEST(Rectangle, ExceptionForLengthIsZero){
//     try {
//         Rectangle(0, 1);
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("this is not a rectangle!", e);
//     }
// }

// TEST(Rectangle, ExceptionForWidthIsZero){
//     try {
//         Rectangle(1, 0);
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("this is not a rectangle!", e);
//     }
// }

// TEST(Rectangle, ExceptionForLengthLessThanZero){
//     try {
//         Rectangle(-1, 1);
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("this is not a rectangle!", e);
//     }
// }

// TEST(Rectangle, ExceptionForWidthLessThanZero){
//     try {
//         Rectangle(1, -1);
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("this is not a rectangle!", e);
//     }
// }

// TEST(Rectangle, AreaInt){
//     Shape* rectangle = new Rectangle(3, 4);
//     ASSERT_EQ(12, rectangle->area());
// }

// TEST(Rectangle, AreaDouble){
//     Shape* rectangle = new Rectangle(3.7, 4.2);
//     ASSERT_DOUBLE_EQ(15.54, rectangle->area());
// }

// TEST(Rectangle, PerimeterInt){
//     Shape* rectangle = new Rectangle(3, 4);
//     ASSERT_EQ(14, rectangle->perimeter());
// }

// TEST(Rectangle, PerimeterDouble){
//     Shape* rectangle = new Rectangle(3.7, 4.2);
//     ASSERT_EQ(15.8, rectangle->perimeter());
// }

// TEST(Rectangle, Type){
//     Shape* rectangle = new Rectangle(3, 4);
//     ASSERT_EQ("rectangle", rectangle->type());
// }