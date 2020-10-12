#define ABS 0.001

#include <string>
#include <vector>
#include "../src/ellipse.h"

using namespace std;

class EllipseTestSuite: public testing::Test {
protected:
    virtual void SetUp() {
        coordinates.push_back(new TwoDimensionalCoordinate(0, 1));
        ellipse = new Ellipse("1",coordinates, 4.2, 3.7);
    }

    virtual void TearDown() {}
    
    Shape* ellipse;
    vector<TwoDimensionalCoordinate*> coordinates;
};

TEST(Ellipse, constructor_with_default_color){
    vector<TwoDimensionalCoordinate*> coordinates;
    coordinates.push_back(new TwoDimensionalCoordinate(0, 1));

    ASSERT_NO_THROW(Ellipse("1",coordinates, 1, 1));
}

TEST_F(EllipseTestSuite, constructor_with_custom_color){
    ASSERT_NO_THROW(Ellipse("1",coordinates, 1, 1, "red"));
}

TEST_F(EllipseTestSuite, exception_for_coordinate_less_than_one){
    coordinates.push_back(new TwoDimensionalCoordinate(1, 1));
    try {
        Ellipse("1",vector<TwoDimensionalCoordinate*>(), 1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_semi_major_axis_is_zero){
    try {
        Ellipse("1",coordinates, 0, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_semi_minor_axis_is_zero){
    try {
        Ellipse("1",coordinates, 1, 0);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_semi_major_axis_less_than_zero){
    try {
        Ellipse("1",coordinates, -1, 1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_semi_minor_axis_less_than_zero){
    try {
        Ellipse("1",coordinates, 1, -1);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST_F(EllipseTestSuite, id){
    ASSERT_EQ("1", ellipse->id());
}

TEST_F(EllipseTestSuite, coordinates){
    EXPECT_EQ(0, ellipse->coordinates()[0]->getX());
    EXPECT_EQ(1, ellipse->coordinates()[0]->getY());
}

TEST_F(EllipseTestSuite, default_color){
    ASSERT_EQ("white", ellipse->color());
}

TEST_F(EllipseTestSuite, custom_color){
    ellipse = new Ellipse("1",coordinates, 1, 1, "red");
    ASSERT_EQ("red", ellipse->color());
}

TEST_F(EllipseTestSuite, area){
    ASSERT_NEAR(48.820, ellipse->area(), ABS);
}

TEST_F(EllipseTestSuite, perimeter){
    ASSERT_NEAR(25.247, ellipse->perimeter(), ABS);
}

TEST_F(EllipseTestSuite, info){
    ASSERT_EQ("Ellipse ([0.000, 1.000], 4.200, 3.700)", ellipse->info());
}

TEST_F(EllipseTestSuite, type){
    ASSERT_EQ("Ellipse", ellipse->type());
}

TEST_F(EllipseTestSuite, exception_for_add_shape){
    try {
        ellipse->addShape(new Ellipse("0",coordinates, 1, 1, "red"));
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_delete_shape){
    try {
        ellipse->deleteShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST_F(EllipseTestSuite, exception_for_get_shape_by_id){
    try {
        ellipse->getShapeById("1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}