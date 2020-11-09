#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/ellipse.h"

class EllipseTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        _coordinates.push_back(new TwoDimensionalCoordinate(-1, 3.14));
        ellipse = new Ellipse("1", _coordinates, 4.2, 3.7);
    }

    virtual void TearDown() {}
    
    std::vector<TwoDimensionalCoordinate*> _coordinates;
    Shape* ellipse;
};

TEST(EllipseTest, constructor_with_default_color){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    ASSERT_NO_THROW(Ellipse("1", coordinates, 4.2, 3.7));
}

TEST(EllipseTest, constructor_with_custom_color){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    ASSERT_NO_THROW(Ellipse("1", coordinates, 1, 1, "red"));
}


TEST(EllipseTest, exception_for_semi_major_axis_is_zero){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Ellipse("1", coordinates, 0, 1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(EllipseTest, exception_for_semi_minor_axis_is_zero){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Ellipse("1", coordinates, 1, 0);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(EllipseTest, exception_for_semi_major_axis_less_than_zero){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Ellipse("1", coordinates, -1, 1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(EllipseTest, exception_for_semi_minor_axis_less_than_zero){
    std::vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Ellipse("1", coordinates, 1, -1);
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, id){
    ASSERT_EQ("1", ellipse->id());
}

TEST_F(EllipseTestSuite, default_color){
    ASSERT_EQ("white", ellipse->color());
}

TEST_F(EllipseTestSuite, custom_color){
    ellipse = new Ellipse("1", _coordinates, 1, 1, "red");
    ASSERT_EQ("red", ellipse->color());
}

TEST_F(EllipseTestSuite, area){
    ASSERT_NEAR(48.820, ellipse->area(), ABS);
}

TEST_F(EllipseTestSuite, perimeter){
    ASSERT_NEAR(25.247, ellipse->perimeter(), ABS);
}

TEST_F(EllipseTestSuite, info){
    ASSERT_EQ("Ellipse ([-1.000, 3.140], 4.200, 3.700)", ellipse->info());
}

TEST_F(EllipseTestSuite, type){
    ASSERT_EQ("Ellipse", ellipse->type());
}

TEST_F(EllipseTestSuite, exception_for_add_shape){
    try {
        ellipse->addShape(new Ellipse("0", _coordinates, 1, 1, "red"));
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_delete_shape){
    try {
        ellipse->deleteShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_get_shape_by_id){
    try {
        ellipse->getShapeById("1");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}