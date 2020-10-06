#include "../src/rectangle.h"

using namespace std;

TEST(Rectangle, ExceptionForLengthIsZero){
    try {
        Rectangle("1", 0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForWidthIsZero){
    try {
        Rectangle("1", 1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForLengthLessThanZero){
    try {
        Rectangle("1", -1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForWidthLessThanZero){
    try {
        Rectangle("1", 1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, AreaInt){
    Shape* rectangle = new Rectangle("1", 3, 4);
    ASSERT_EQ(12, rectangle->area());
}

TEST(Rectangle, AreaDouble){
    Shape* rectangle = new Rectangle("1", 3.7, 4.2);
    ASSERT_DOUBLE_EQ(15.54, rectangle->area());
}

TEST(Rectangle, PerimeterInt){
    Shape* rectangle = new Rectangle("1", 3, 4);
    ASSERT_EQ(14, rectangle->perimeter());
}

TEST(Rectangle, PerimeterDouble){
    Shape* rectangle = new Rectangle("1", 3.7, 4.2);
    ASSERT_EQ(15.8, rectangle->perimeter());
}

TEST(Rectangle, Info){
    Shape* rectangle = new Rectangle("1", 3, 4);
    ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle->info());
}

TEST(Rectangle, DefaultColor){
    Shape* rectangle = new Rectangle("1", 3, 4);
    ASSERT_EQ("white", rectangle->color());
}

TEST(Rectangle, RedColor){
    Shape* rectangle = new Rectangle("1", 3, 4, "red");
    ASSERT_EQ("red", rectangle->color());
}

TEST(Rectangle, ExceptionForAddShape){
    Shape* rectangle = new Rectangle("1", 3, 4);
    try {
        rectangle->addShape(new Rectangle("1", 3, 4));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST(Rectangle, ExceptionForDeleteShape){
    Shape* rectangle = new Rectangle("1", 3, 4);
    try {
        rectangle->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST(Rectangle, ExceptionForGetShapeById){
    Shape* rectangle = new Rectangle("1", 3, 4);
    try {
        rectangle->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}