// #include <gtest/gtest.h>
// #include "../src/compound_shape.h"
// #include "../src/ellipse.h"
// #include "../src/rectangle.h"
// #include "../src/triangle.h"
// #include "../src/two_dimensional_coordinate.h"

// using namespace std;

// class CompoundShapeTest: public testing::Test {
//     protected:
//     virtual void SetUp() {

//         vector<TwoDimensionalCoordinate*> coordinates;
//         coordinates.push_back(new TwoDimensionalCoordinate(0, 0));
//         coordinates.push_back(new TwoDimensionalCoordinate(3, 0));
//         coordinates.push_back(new TwoDimensionalCoordinate(0, 4));

//         ellipse_1 = new Ellipse("1", 4, 3);
//         rectangle_2 = new Rectangle("2", 3, 4);
//         triangle_3 = new Triangle("3", coordinates);

//         shapes->push_back(ellipse_1);
//         shapes->push_back(rectangle_2);
//         shapes->push_back(triangle_3);

//         ellipse_4 = new Ellipse("4", 4.2, 3.7);
//         rectangle_5 = new Rectangle("5", 3.7, 4.2);
//         triangle_6 = new Triangle("6", coordinates);
//     }

//     virtual void TearDown() {
//         shapes->clear();
//         delete ellipse_1;
//         delete rectangle_2;
//         delete triangle_3;
//         delete ellipse_4;
//         delete rectangle_5;
//         delete triangle_6;
//     }

//     vector<Shape*> *shapes = new vector<Shape*>();

//     Shape* ellipse_1;
//     Shape* rectangle_2;
//     Shape* triangle_3;
//     Shape* ellipse_4;
//     Shape* rectangle_5;
//     Shape* triangle_6;
// };

// TEST(Ellipse, ExceptionForCallGetShapeById){
//     Shape* ellipse = new Ellipse("1", 4, 3);
//     try {
//         getShapeById(ellipse, "1");
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("Only compound shape can get shape!", e);
//     }
// }

// TEST(Rectangle, ExceptionForCallGetShapeById){
//     Shape* rectangle = new Rectangle("1", 3, 4);
//     try {
//         getShapeById(rectangle, "1");
//         FAIL();
//     }catch(string e) {
//         ASSERT_EQ("Only compound shape can get shape!", e);
//     }
// }


// TEST_F(TriangleTest, FilterShapeArea){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape *> vector = filterShape(triangle, AreaFilter(12, 1));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ(6, vector[0]->area());

//     vector = filterShape(triangle, AreaFilter(5, 1));

//     ASSERT_EQ(0, vector.size());
// }


// TEST_F(TriangleTest, FilterShapePerimeter){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape *> vector = filterShape(triangle, PerimeterFilter(12, 1));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ(6, vector[0]->area());

//     vector = filterShape(triangle, PerimeterFilter(5, 1));

//     ASSERT_EQ(0, vector.size());
// }

// TEST_F(TriangleTest, FilterShapeByColor){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape *> vector = filterShape(triangle, ColorFilter("White"));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ("White", vector[0]->color());

//     vector = filterShape(triangle, ColorFilter("Red"));

//     ASSERT_EQ(0, vector.size());
// }

// TEST_F(TriangleTest, FilterShapeByType){
//     Shape* triangle = new Triangle("1", triangleVector);
//     vector<Shape*> vector = filterShape(triangle, TypeFilter("Triangle"));

//     ASSERT_EQ(1, vector.size());
//     ASSERT_EQ("Triangle", vector[0]->type());

//     vector = filterShape(triangle, TypeFilter("Rectangle"));

//     ASSERT_EQ(0, vector.size());
// }