#define ABS 0.001

#include "../src/rectangle.h"

class RectangleTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        rectangle = new Rectangle("1", 2, 2);
    }

    virtual void TearDown() {}

    Shape* rectangle;
};

TEST(Rectangle, no_exception_constructor_with_default_color){
    ASSERT_NO_THROW(Rectangle("1", 2, 2));
}

TEST(Rectangle, no_exception_constructor_with_custom_color){
    ASSERT_NO_THROW(Rectangle("1", 2, 2, "red"));
}

TEST(Rectangle, exception_for_length_is_zero){
    try {
        Rectangle("1", 0, 1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, exception_for_width_is_zero){
    try {
        Rectangle("1", 1, 0);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, exception_for_length_less_than_zero){
    try {
        Rectangle("1", -1, 1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, exception_for_width_less_than_zero){
    try {
        Rectangle("1", 1, -1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST_F(RectangleTestSuite, id){
    ASSERT_EQ("1", rectangle->id());
}


TEST_F(RectangleTestSuite, default_color){
    ASSERT_EQ("white", rectangle->color());
}

TEST_F(RectangleTestSuite, custom_color){
    rectangle = new Rectangle("1", 2, 2, "red");
    ASSERT_EQ("red", rectangle->color());
}

TEST_F(RectangleTestSuite, area){
    ASSERT_NEAR(4, rectangle->area(), ABS);
}

TEST_F(RectangleTestSuite, perimeter){
    ASSERT_NEAR(8, rectangle->perimeter(), ABS);
}

TEST_F(RectangleTestSuite, info){
    ASSERT_EQ("Rectangle (2.000, 2.000)", rectangle->info());
}

TEST_F(RectangleTestSuite, type){
    ASSERT_EQ("Rectangle", rectangle->type());
}

TEST_F(RectangleTestSuite, exception_for_add_shape){
    try {
        rectangle->addShape(new Rectangle("0", 2, 2));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST_F(RectangleTestSuite, exception_for_delete_shape){
    try {
        rectangle->deleteShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST_F(RectangleTestSuite, exception_for_get_shape_by_id){
    try {
        rectangle->getShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}