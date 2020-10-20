#define ABS 0.001

#include <gtest/gtest.h>
#include "../src/compound_shape.h"
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"

using namespace std;

class MoveVisitorTestSuite: public testing::Test {
    protected:
    virtual void SetUp() {

        vector<TwoDimensionalCoordinate*> ellipseCoordinates;
        ellipseCoordinates.push_back(new TwoDimensionalCoordinate(0, 1));
        ellipse = new Ellipse("1",ellipseCoordinates, 4.2, 3.7);

        vector<TwoDimensionalCoordinate*> rectangleCoordinates;
        rectangleCoordinates.push_back(new TwoDimensionalCoordinate(1, 1));
        rectangleCoordinates.push_back(new TwoDimensionalCoordinate(-1, 1));
        rectangleCoordinates.push_back(new TwoDimensionalCoordinate(-1, -1));
        rectangleCoordinates.push_back(new TwoDimensionalCoordinate(1, -1));
        rectangle = new Rectangle("2", rectangleCoordinates);

        vector<TwoDimensionalCoordinate*> triangleCoordinates;
        triangleCoordinates.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleCoordinates.push_back(new TwoDimensionalCoordinate(0, -3));
        triangleCoordinates.push_back(new TwoDimensionalCoordinate(-4, 0));
        triangle = new Triangle("3", triangleCoordinates);

        vector<Shape*>* shapes = new vector<Shape*>();
        shapes->push_back(ellipse);
        shapes->push_back(rectangle);
        shapes->push_back(triangle);

        compoundShape = new CompoundShape("4", shapes);
    }

    virtual void TearDown() {}

    Shape* ellipse;
    Shape* rectangle;
    Shape* triangle;
    Shape* compoundShape;
};