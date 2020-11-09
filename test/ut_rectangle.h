#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/rectangle.h"

class RectangleTestSuite: public testing::Test {
protected:
    virtual void SetUp() {

        _coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
        _coordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
        _coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
        _coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

        rectangle = new Rectangle("1", _coordinates);
    }

    virtual void TearDown() {}

    Shape* rectangle;
    std::vector<TwoDimensionalCoordinate*> _coordinates;
};

TEST(RectangleTest, no_exception_constructor_with_default_color){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

    ASSERT_NO_THROW(Rectangle("1", coordinates));
}

TEST(RectangleTest, no_exception_constructor_with_custom_color){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

    ASSERT_NO_THROW(Rectangle("1", coordinates, "red"));
}

TEST(RectangleTest, exception_for_coordinate_less_than_four){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

    try {
        Rectangle("1", coordinates);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(RectangleTest, exception_for_coordinate_more_than_four){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, -1));
    try {
        Rectangle("1", coordinates);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(RectangleTest, exception_for_length_is_zero){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
    coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

    try {
        Rectangle("1", coordinates);
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
    rectangle = new Rectangle("1", _coordinates, "red");
    ASSERT_EQ("red", rectangle->color());
}

TEST_F(RectangleTestSuite, area){
    ASSERT_NEAR(4, rectangle->area(), ABS);
}

TEST_F(RectangleTestSuite, perimeter){
    ASSERT_NEAR(8, rectangle->perimeter(), ABS);
}

TEST_F(RectangleTestSuite, info){
    ASSERT_EQ("Rectangle ([1.000, 1.000], [-1.000, 1.000], [-1.000, -1.000], [1.000, -1.000])", rectangle->info());
}

TEST_F(RectangleTestSuite, type){
    ASSERT_EQ("Rectangle", rectangle->type());
}

TEST_F(RectangleTestSuite, exception_for_add_shape){
    try {
        rectangle->addShape(new Rectangle("0", _coordinates));
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