#define ABS 0.001

#include <string>
#include <vector>
#include "../src/rectangle.h"

using namespace std;

class RectangleTest: public testing::Test {
protected:
    virtual void SetUp() {
        coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
        coordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
        coordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
        coordinates.push_back(new TwoDimensionalCoordinate(1, -1));

        rectangle = new Rectangle("1", coordinates);
    }

    virtual void TearDown() {
        delete rectangle;
        coordinates.clear();
    }
    Shape* rectangle;
    vector<TwoDimensionalCoordinate*> coordinates;
};

TEST_F(RectangleTest, no_exception_constructor_with_default_color){
    ASSERT_NO_THROW(Rectangle("1", coordinates));
}

TEST_F(RectangleTest, no_exception_constructor_with_custom_color){
    ASSERT_NO_THROW(Rectangle("1",coordinates, "red"));
}

TEST_F(RectangleTest, exception_for_coordinate_less_than_four){
    coordinates.pop_back();
    try {
        Rectangle("1", coordinates);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST_F(RectangleTest, exception_for_coordinate_more_than_four){
    coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
    try {
        Rectangle("1", coordinates);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}


TEST_F(RectangleTest, id){
    ASSERT_EQ("1", rectangle->id());
}

TEST_F(RectangleTest, coordinates){
    EXPECT_EQ(1, rectangle->coordinates()[0]->getX());
    EXPECT_EQ(1, rectangle->coordinates()[0]->getY());

    EXPECT_EQ(-1, rectangle->coordinates()[1]->getX());
    EXPECT_EQ(1, rectangle->coordinates()[1]->getY());

    EXPECT_EQ(-1, rectangle->coordinates()[2]->getX());
    EXPECT_EQ(-1, rectangle->coordinates()[2]->getY());

    EXPECT_EQ(1, rectangle->coordinates()[3]->getX());
    EXPECT_EQ(-1, rectangle->coordinates()[3]->getY());
}

TEST_F(RectangleTest, default_color){
    ASSERT_EQ("white", rectangle->color());
}

TEST_F(RectangleTest, custom_color){
    rectangle = new Rectangle("1",coordinates, "red");
    ASSERT_EQ("red", rectangle->color());
}

TEST_F(RectangleTest, area){
    ASSERT_NEAR(-1, rectangle->area(), ABS);
}

TEST_F(RectangleTest, perimeter){
    ASSERT_NEAR(-1, rectangle->perimeter(), ABS);
}

TEST_F(RectangleTest, info){
    ASSERT_EQ("Rectangle ([(1.000, 1.000), (-1.000, 1.000), (-1.000, -1.000), (1.000, -1.000)])", rectangle->info());
}

TEST_F(RectangleTest, type){
    ASSERT_EQ("Rectangle", rectangle->type());
}

TEST_F(RectangleTest, exception_for_add_shape){
    try {
        rectangle->addShape(new Rectangle("0",coordinates));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

// TEST_F(RectangleTest, exception_for_delete_shape){
//     try {
//         ellipse->deleteShapeById("1");
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("Only compound shape can delete shape!", e);
//     }
// }

// TEST_F(RectangleTest, exception_for_get_shape_by_id){
//     try {
//         ellipse->getShapeById("1");
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("Only compound shape can get shape!", e);
//     }
// }