// #define ABS 0.001

#include <gtest/gtest.h>
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"

class VisitorTestSuite: public testing::Test {
protected:
    virtual void SetUp() {

        std::vector<TwoDimensionalCoordinate*> elllipse_1_coordinate = {};
        elllipse_1_coordinate.push_back(new TwoDimensionalCoordinate(-1, 3.14));

        std::vector<TwoDimensionalCoordinate*> rectangle_2_coordinates = {};
        rectangle_2_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        rectangle_2_coordinates.push_back(new TwoDimensionalCoordinate(-3, 0));
        rectangle_2_coordinates.push_back(new TwoDimensionalCoordinate(-3, -4));
        rectangle_2_coordinates.push_back(new TwoDimensionalCoordinate(0, -4));

        std::vector<TwoDimensionalCoordinate*> triangle_3_coordinates = {};
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        triangle_3_coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_1 = new Ellipse("1", elllipse_1_coordinate, 4, 3);
        rectangle_2 = new Rectangle("2", rectangle_2_coordinates);
        triangle_3 = new Triangle("3", triangle_3_coordinates);

        shapes.push_back(ellipse_1);
        shapes.push_back(rectangle_2);
        shapes.push_back(triangle_3);
        compoundShape_7 = new CompoundShape("7", shapes);

        std::vector<TwoDimensionalCoordinate*> elllipse_4_coordinate = {};
        elllipse_4_coordinate.push_back(new TwoDimensionalCoordinate(-1, 3.14));

        std::vector<TwoDimensionalCoordinate*> rectangle_5_coordinates = {};
        rectangle_5_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        rectangle_5_coordinates.push_back(new TwoDimensionalCoordinate(3.7, 0));
        rectangle_5_coordinates.push_back(new TwoDimensionalCoordinate(3.7, 4.2));
        rectangle_5_coordinates.push_back(new TwoDimensionalCoordinate(0, 4.2));

        std::vector<TwoDimensionalCoordinate*> triangle_6_coordinates = {};
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
        triangle_6_coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

        ellipse_4 = new Ellipse("4", elllipse_4_coordinate, 4.2, 3.7);
        rectangle_5 = new Rectangle("5", rectangle_5_coordinates);
        triangle_6 = new Triangle("6", triangle_6_coordinates);
    }

    virtual void TearDown() {}

    std::list<Shape*> shapes = {};
    Shape* ellipse_1;
    Shape* rectangle_2;
    Shape* triangle_3;
    Shape* ellipse_4;
    Shape* rectangle_5;
    Shape* triangle_6;
    Shape* compoundShape_7;
};

TEST_F(VisitorTestSuite, ellipse_area) {
    AreaVisitor* v = new AreaVisitor();
    ellipse_1->accept(v);
    ASSERT_NEAR(37.699, v->area(), ABS);
}

TEST_F(VisitorTestSuite, rectangle_area) {
    AreaVisitor* v = new AreaVisitor();
    rectangle_2->accept(v);
    ASSERT_NEAR(12.000, v->area(), ABS);
}

TEST_F(VisitorTestSuite, triangle_area) {
    AreaVisitor* v = new AreaVisitor();
    triangle_3->accept(v);
    ASSERT_NEAR(6.000, v->area(), ABS);
}

TEST_F(VisitorTestSuite, compound_shape_area) {
    AreaVisitor* v = new AreaVisitor();
    compoundShape_7->accept(v);
    ASSERT_NEAR(55.699, v->area(), ABS);
}

TEST_F(VisitorTestSuite, compound_shape_area_level_3_tree_structure) {
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = {};
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    AreaVisitor* v = new AreaVisitor();
    compoundShape_7->accept(v);
    ASSERT_NEAR(126.059, v->area(), ABS);
}

TEST_F(VisitorTestSuite, ellipse_info) {
    InfoVisitor* v = new InfoVisitor();
    ellipse_1->accept(v);
    ASSERT_EQ("Ellipse ([-1.000, 3.140], 4.000, 3.000)", v->info());
}

TEST_F(VisitorTestSuite, rectangle_info) {
    InfoVisitor* v = new InfoVisitor();
    rectangle_2->accept(v);
    ASSERT_EQ("Rectangle ([0.000, 0.000], [-3.000, 0.000], [-3.000, -4.000], [0.000, -4.000])", v->info());
}

TEST_F(VisitorTestSuite, triangle_info) {
    InfoVisitor* v = new InfoVisitor();
    triangle_3->accept(v);
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", v->info());
}

TEST_F(VisitorTestSuite, compound_shape_info) {
    InfoVisitor* v = new InfoVisitor();
    compoundShape_7->accept(v);
    ASSERT_EQ("Compound Shape {Ellipse ([-1.000, 3.140], 4.000, 3.000), Rectangle ([0.000, 0.000], [-3.000, 0.000], [-3.000, -4.000], [0.000, -4.000]), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", v->info());
}


TEST_F(VisitorTestSuite, compound_shape_info_level_3_tree_structure) {
    shapes = {};
    shapes.push_back(ellipse_4);
    Shape* compoundShape_8 = new CompoundShape("8", shapes);

    shapes = {};
    shapes.push_back(triangle_6);
    shapes.push_back(rectangle_5);
    Shape* compoundShape_9 = new CompoundShape("9", shapes);

    compoundShape_8->addShape(compoundShape_9);
    compoundShape_7->addShape(compoundShape_8);

    InfoVisitor* v = new InfoVisitor();
    compoundShape_7->accept(v);
    ASSERT_EQ("Compound Shape {Ellipse ([-1.000, 3.140], 4.000, 3.000), Rectangle ([0.000, 0.000], [-3.000, 0.000], [-3.000, -4.000], [0.000, -4.000]), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Ellipse ([-1.000, 3.140], 4.200, 3.700), Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle ([0.000, 0.000], [3.700, 0.000], [3.700, 4.200], [0.000, 4.200])}}}", v->info());
}