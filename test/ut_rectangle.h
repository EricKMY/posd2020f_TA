#define ABS 0.001

#include "../src/rectangle.h"
#include "../src/two_dimensional_coordinate.h"

class RectangleTestSuite: public testing::Test {
protected:
    virtual void SetUp() {


        position = new TwoDimensionalCoordinate(0, 0);

        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(2, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(2, 2));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 2));

        rectangle = new Rectangle("1", position, coordinates);
    }

    virtual void TearDown() {}

    Shape* rectangle;
    TwoDimensionalCoordinate *position;
    std::vector<TwoDimensionalCoordinate*> coordinates;
};

TEST_F(RectangleTestSuite, no_exception_constructor_with_default_color){
    ASSERT_NO_THROW(Rectangle("1", position, coordinates));
}

TEST_F(RectangleTestSuite, no_exception_constructor_with_custom_color){
    ASSERT_NO_THROW(Rectangle("1", position, coordinates, "red"));
}

TEST_F(RectangleTestSuite, exception_for_length_is_zero){
    try {
        std::vector<TwoDimensionalCoordinate *> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 2));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 2));

        Rectangle("1", position, coordinates);
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
    rectangle = new Rectangle("1", position, coordinates, "red");
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

// TEST_F(RectangleTestSuite, type){
//     ASSERT_EQ("Rectangle", rectangle->type());
// }

// TEST_F(RectangleTestSuite, exception_for_add_shape){
//     try {
//         rectangle->addShape(new Rectangle("0", 2, 2));
//         FAIL();
//     }catch(std::string e) {
//         ASSERT_EQ("Only compound shape can add shape!", e);
//     }
// }

// TEST_F(RectangleTestSuite, exception_for_delete_shape){
//     try {
//         rectangle->deleteShapeById("1");
//         FAIL();
//     }catch(std::string e) {
//         ASSERT_EQ("Only compound shape can delete shape!", e);
//     }
// }

// TEST_F(RectangleTestSuite, exception_for_get_shape_by_id){
//     try {
//         rectangle->getShapeById("1");
//         FAIL();
//     }catch(std::string e) {
//         ASSERT_EQ("Only compound shape can get shape!", e);
//     }
// }