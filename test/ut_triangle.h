#define ABS 0.001

#include "../src/triangle.h"

class TriangleTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, -3));
        coordinates.push_back(new TwoDimensionalCoordinate(-4, 0));

        triangle = new Triangle("1", coordinates);
    }

    virtual void TearDown() {}

    Shape* triangle;
    std::vector<TwoDimensionalCoordinate*> coordinates;
};

TEST(Triangle, no_exception_constructor){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
    coordinates.push_back(new TwoDimensionalCoordinate(0, -3));
    coordinates.push_back(new TwoDimensionalCoordinate(-4, 0));

    ASSERT_NO_THROW(Triangle("1", coordinates));
}

TEST_F(TriangleTestSuite, exception_for_coordinate_less_than_three){
    coordinates.pop_back();
    try {
        Triangle("1", coordinates);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST_F(TriangleTestSuite, exception_for_coordinate_more_than_three){
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Triangle("1", coordinates);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST_F(TriangleTestSuite, default_color){
    ASSERT_EQ("white", triangle->color());
}

TEST_F(TriangleTestSuite, custom_color){
    triangle = new Triangle("1",coordinates, "red");
    ASSERT_EQ("red", triangle->color());
}

TEST_F(TriangleTestSuite, id){
    ASSERT_EQ("1", triangle->id());
}

TEST_F(TriangleTestSuite, area){
    ASSERT_NEAR(6, triangle->area(), ABS);
}

TEST_F(TriangleTestSuite, perimeter){
    ASSERT_NEAR(12, triangle->perimeter(), ABS);
}

TEST_F(TriangleTestSuite, info){
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", triangle->info());
}

TEST_F(TriangleTestSuite, type){
    ASSERT_EQ("Triangle", triangle->type());
}

TEST_F(TriangleTestSuite, exception_for_add_shape){
    try {
        triangle->addShape(new Triangle("0",coordinates));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST_F(TriangleTestSuite, exception_for_delete_shape){
    try {
        triangle->deleteShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}