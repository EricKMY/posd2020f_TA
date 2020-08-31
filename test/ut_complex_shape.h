#include "../src/complex_shape.h"




class ComplexShapeTest: public testing::Test {
    protected:
    void SetUp() {

        ellipse = new Ellipse("1", 3, 4);
        rectangle = new Rectangle("2", 3, 4);

        vector<TwoDimensionalCoordinate*> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle("3", triangleVector);

        shapes.push_back(ellipse);
        shapes.push_back(rectangle);
        shapes.push_back(triangle);


        ellipse2 = new Ellipse("5", 3.7, 4.2);
        rectangle2 = new Rectangle("6", 3.7, 4.2);
        triangle2 = new Triangle("7", triangleVector);

    }
    vector<Shape*> shapes;

    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;

    Shape* ellipse2;
    Shape* rectangle2;
    Shape* triangle2;
};



TEST(ComplexShape, ExceptionForEmptyShapes){
    
    vector<Shape*> shapes;
    try {
        new ComplexShape("4", shapes);
        FAIL();
    }catch(string e) {
        ASSERT_EQ("This is not a complexShape!", e);
    }
}

TEST_F(ComplexShapeTest, Area){
    vector<Shape*> shapes;
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_NEAR(55.6991, complex_shape->area(), 0.0001);
}

TEST_F(ComplexShapeTest, Perimeter){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_NEAR(47.1327, complex_shape->perimeter(), 0.0001);
}

TEST_F(ComplexShapeTest, Info){
    Shape* complex_shape = new ComplexShape("4", shapes);
    ASSERT_EQ("Ellipse (3.000, 4.000)\nRectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", complex_shape->info());
}


TEST_F(ComplexShapeTest, AddShape){
    vector<Shape*> _shapes;
    _shapes.push_back(ellipse);

    Shape* complex_shape = new ComplexShape("4", _shapes);
    complex_shape.addShape(rectangle);
    complex_shape.addShape(triangle);

    ASSERT_NEAR(55.6991, complex_shape->area(), 0.0001);
    ASSERT_NEAR(47.1327, complex_shape->perimeter(), 0.0001);
    ASSERT_EQ("Ellipse (3.000, 4.000)\nRectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", complex_shape->info());
}

TEST_F(ComplexShapeTest, DeleteShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);
    complex_shape.deleteShapeById("1");

    ASSERT_EQ(18, complex_shape->area());
    ASSERT_EQ(26, complex_shape->perimeter());
    ASSERT_EQ("Rectangle (3.000, 4.000)\nTriangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExecptionForDeleteShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);

    try {
        complex_shape.deleteShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }
}

TEST_F(ComplexShapeTest, GetShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);
    Shape *shape = complex_shape.getShapeById("3");


    ASSERT_EQ("3", shape->Id());
    ASSERT_EQ(6, shape->area());
    ASSERT_EQ(12, shape->perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", shape->info());
}

TEST_F(ComplexShapeTest, ExecptionForGetShapeById){
    Shape* complex_shape = new ComplexShape("4", shapes);

    try {
        complex_shape.getShapeById("-1");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }
}


TEST_F(ComplexShapeTest, GetShapeById_lv3){
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> shapes2;
    shapes2.push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> shapes3;
    shapes3.push_back(triangle2);
    shapes3.push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2.addShape(complex_shape3);
    complex_shape.addShape(complex_shape2);

    //--------------------------------------------------

    Shape *shape = complex_shape.getShapeById("9");

    ASSERT_EQ("9", shape->Id());
    ASSERT_NEAR(21.54, shape->area(), 0.01); //triangle 6, rectangle 15.54
    ASSERT_NEAR(27.8, shape->perimeter(), 0.01);//triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}", shape->info());

    Shape *shape = complex_shape.getShapeById("8");

    ASSERT_EQ("8", shape->Id());
    ASSERT_NEAR(70.3603, shape->area(), 0.0001); //ellipse 48.8203, triangle 6, rectangle 15.54
    ASSERT_NEAR(52.1893, shape->perimeter(), 0.0001);//ellipse 24.3893, triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Ellipse (3.700, 4.200), Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}", shape->info());

    Shape *shape = complex_shape.getShapeById("4");

    ASSERT_EQ("4", shape->Id());
    ASSERT_NEAR(126.0594, shape->area(), 0.0001); //complexShape 55.6991, ellipse 48.8203, triangle 6, rectangle 15.54
    ASSERT_NEAR(99.3220, shape->perimeter(), 0.0001);//complexShape 47.1327, ellipse 24.3893, triangle 12, rectangle 15.8
    ASSERT_EQ("Complex Shape {Ellipse (3.000, 4.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Complex Shape {Ellipse (3.700, 4.200), Complex Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (3.700, 4.200)}}}", shape->info());
}

TEST_F(ComplexShapeTest, DeleteShapeById_lv3){
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> shapes2;
    shapes2.push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> shapes3;
    shapes3.push_back(triangle2);
    shapes3.push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2.addShape(complex_shape3);
    complex_shape.addShape(complex_shape2);

    //--------------------------------------------------
    
    complex_shape.deleteShapeById("9");

    ASSERT_NEAR(104.5194, complex_shape->area(), 0.0001);
    ASSERT_NEAR(71.5220, complex_shape->perimeter(), 0.0001);
    ASSERT_EQ("Complex Shape {Ellipse (3.000, 4.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Complex Shape {Ellipse (3.700, 4.200)}}", complex_shape->info());

    complex_shape.deleteShapeById("8");

    ASSERT_NEAR(55.6991, complex_shape->area(), 0.0001);
    ASSERT_NEAR(47.1327, complex_shape->perimeter(), 0.0001);
    ASSERT_EQ("Complex Shape {Ellipse (3.000, 4.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}", complex_shape->info());
}

TEST_F(ComplexShapeTest, ExecptionForDeleteShapeById_lv3){
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> shapes2;
    shapes2.push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> shapes3;
    shapes3.push_back(triangle2);
    shapes3.push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2.addShape(complex_shape3);
    complex_shape.addShape(complex_shape2);

    //--------------------------------------------------

    try {
        complex_shape.deleteShapeById("10");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }

    try {
        complex_shape2.deleteShapeById("4");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }

    try {
        complex_shape3.deleteShapeById("8");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected delete shape but shape not found", e);
    }
}

TEST_F(ComplexShapeTest, ExecptionForGetShapeById_lv3){
    Shape* complex_shape = new ComplexShape("4", shapes);

    vector<Shape*> shapes2;
    shapes2.push_back(ellipse2);
    Shape* complex_shape2 = new ComplexShape("8", shapes2);

    vector<Shape*> shapes3;
    shapes3.push_back(triangle2);
    shapes3.push_back(rectangle2);
    Shape* complex_shape3 = new ComplexShape("9", shapes3);

    complex_shape2.addShape(complex_shape3);
    complex_shape.addShape(complex_shape2);

    //--------------------------------------------------

    try {
        complex_shape.getShapeById("11");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }

    try {
        complex_shape2.getShapeById("3");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }

    try {
        complex_shape3.getShapeById("7");
        FAIL();
    }catch(string e) {
        ASSERT_EQ("expected get shape but shape not found", e);
    }
}