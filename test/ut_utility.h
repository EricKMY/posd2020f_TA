#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/utility.h"

using namespace std;

class UtlilityTest: public testing::Test {
    protected:
    virtual void SetUp() {

        vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_1 = new Ellipse("1", 4, 3, "Red");
        rectangle_2 = new Rectangle("2", 3, 4, "Blue");
        triangle_3 = new Triangle("3", coordinates, "Yellow");

        shapes->push_back(ellipse_1);
        shapes->push_back(rectangle_2);
        shapes->push_back(triangle_3);

        compoundShape_7 = new CompoundShape("7", shapes);

        ellipse_4 = new Ellipse("4", 4.2, 3.7, "Yellow");
        rectangle_5 = new Rectangle("5", 3.7, 4.2, "Blue");
        triangle_6 = new Triangle("6", coordinates, "Red");

        shapes = new vector<Shape*>();
        shapes->push_back(ellipse_4);
        Shape* compoundShape_8 = new CompoundShape("8", shapes);

        shapes = new vector<Shape*>();
        shapes->push_back(triangle_6);
        shapes->push_back(rectangle_5);
        Shape* compoundShape_9 = new CompoundShape("9", shapes);

        compoundShape_8->addShape(compoundShape_9);
        compoundShape_7->addShape(compoundShape_8);
    }

    virtual void TearDown() {
        shapes->clear();
        delete ellipse_1;
        delete rectangle_2;
        delete triangle_3;
        delete ellipse_4;
        delete rectangle_5;
        delete triangle_6;
    }

    vector<Shape*> *shapes = new vector<Shape*>();

    Shape* ellipse_1;
    Shape* rectangle_2;
    Shape* triangle_3;
    Shape* ellipse_4;
    Shape* rectangle_5;
    Shape* triangle_6;
    Shape* compoundShape_7;
};

TEST_F(UtlilityTest, ExceptionForRectangleGetShapeById) {
    try {
        getShapeById(rectangle_2, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTest, ExceptionForEllipseGetShapeById) {
    try {
        getShapeById(ellipse_1, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTest, ExceptionForTriangleGetShapeById) {
    try {
        getShapeById(triangle_3, "1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtlilityTest, CompoundShapeGetShapeById) {
    Shape *shape_1 = getShapeById(compoundShape_7, "1");
    Shape *shape_2 = getShapeById(compoundShape_7, "2");
    Shape *shape_3 = getShapeById(compoundShape_7, "3");

    EXPECT_EQ("1", shape_1->id());
    EXPECT_EQ("Red", shape_1->color());
    EXPECT_NEAR(37.699, shape_1->area(), 0.001);
    EXPECT_NEAR(22.849, shape_1->perimeter(), 0.001);
    EXPECT_EQ("Ellipse (4.000, 3.000)", shape_1->info());
    
    EXPECT_EQ("2", shape_2->id());
    EXPECT_EQ("Blue", shape_2->color());
    EXPECT_NEAR(12, shape_2->area(), 0.001);
    EXPECT_NEAR(14, shape_2->perimeter(), 0.001);
    EXPECT_EQ("Rectangle (3.000, 4.000)", shape_2->info());

    EXPECT_EQ("3", shape_3->id());
    EXPECT_EQ("Yellow", shape_3->color());
    EXPECT_NEAR(6, shape_3->area(), 0.001);
    EXPECT_NEAR(12, shape_3->perimeter(), 0.001);
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape_3->info());
}

TEST_F(UtlilityTest, CompoundShapeFilterShapeArea) {

    vector<Shape*> vector = filterShape(compoundShape_7, AreaFilter(12, 1));

    EXPECT_EQ(3, vector.size());

    EXPECT_EQ("2", vector[0]->id());
    EXPECT_EQ("Rectangle (3.000, 4.000)", vector[0]->info());
    EXPECT_EQ(12, vector[0]->area());

    EXPECT_EQ("3", vector[1]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vector[1]->info());
    EXPECT_EQ(6, vector[1]->area());
    
    EXPECT_EQ("6", vector[2]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vector[2]->info());
    EXPECT_EQ(6, vector[2]->area());
}


TEST_F(UtlilityTest, CompoundShapeFilterShapePerimeter) {
    vector<Shape*> vector = filterShape(compoundShape_7, PerimeterFilter(12, 1));

    EXPECT_EQ(2, vector.size());

    EXPECT_EQ("3", vector[0]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vector[0]->info());
    EXPECT_EQ(12, vector[0]->perimeter());

    EXPECT_EQ("6", vector[1]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vector[1]->info());
    EXPECT_EQ(12, vector[1]->perimeter());
}

TEST_F(UtlilityTest, CompoundShapeFilterShapeType) {
    vector<Shape*> vector = filterShape(compoundShape_7, TypeFilter("Ellipse"));

    EXPECT_EQ(2, vector.size());

    EXPECT_EQ("1", vector[0]->id());
    EXPECT_EQ("Ellipse (4.000, 3.000)", vector[0]->info());
    EXPECT_EQ("Red", vector[0]->color());

    EXPECT_EQ("4", vector[1]->id());
    EXPECT_EQ("Ellipse (4.200, 3.700)", vector[1]->info());
    EXPECT_EQ("Yellow", vector[1]->color());
}

TEST_F(UtlilityTest, CompoundShapeFilterShapeColor) {

    vector<Shape*> vector = filterShape(compoundShape_7, ColorFilter("Red"));

    EXPECT_EQ(2, vector.size());

    EXPECT_EQ("1", vector[0]->id());
    EXPECT_EQ("Ellipse (4.000, 3.000)", vector[0]->info());
    EXPECT_EQ("Red", vector[0]->color());

    EXPECT_EQ("6", vector[1]->id());
    EXPECT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", vector[1]->info());
    EXPECT_EQ("Red", vector[1]->color());
}

// TEST_F(UtlilityTest, FilterShapeArea){
//     vector<Shape *> vector = filterShape(triangle, AreaFilter(12, 1));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ(6, vector[0]->area());

//     vector = filterShape(triangle, AreaFilter(5, 1));

//     ASSERT_EQ(0, vector.size());
// }


// TEST_F(UtlilityTest, FilterShapePerimeter){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape *> vector = filterShape(triangle, PerimeterFilter(12, 1));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ(6, vector[0]->area());

//     vector = filterShape(triangle, PerimeterFilter(5, 1));

//     ASSERT_EQ(0, vector.size());
// }

// TEST_F(UtlilityTest, FilterShapeByColor){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape *> vector = filterShape(triangle, ColorFilter("White"));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ("White", vector[0]->color());

//     vector = filterShape(triangle, ColorFilter("Red"));

//     ASSERT_EQ(0, vector.size());
// }

// TEST_F(UtlilityTest, FilterShapeByType){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape*> vector = filterShape(triangle, TypeFilter("Triangle"));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ("Triangle", vector[0]->type());

//     vector = filterShape(triangle, TypeFilter("Rectangle"));

//     ASSERT_EQ(0, vector.size());
// }