#include "../src/rectangle.h"


TEST(Rectangle, ExceptionForLengthIsZero){
    try {
        Rectangle(0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForWidthIsZero){
    try {
        Rectangle(1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForLengthLessThanZero){
    try {
        Rectangle(-1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForWidthLessThanZero){
    try {
        Rectangle(1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, AreaInt){
    Shape* rectangle = new Rectangle(3, 4);
    ASSERT_EQ(12, rectangle->area());
}

TEST(Rectangle, AreaDouble){
    Shape* rectangle = new Rectangle(3.7, 4.2);
    ASSERT_DOUBLE_EQ(15.54, rectangle->area());
}

TEST(Rectangle, Info){
    Shape* rectangle = new Rectangle(3, 4);
    ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle->info());
}
