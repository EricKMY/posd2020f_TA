#include "shape.h"

using namespace std;

Shape::Shape(string id , vector<TwoDimensionalCoordinate*> coordinates): _id(id), _coordinates(coordinates), _color("white") {}

Shape::Shape(string id, vector<TwoDimensionalCoordinate*> coordinates, string color): _id(id), _coordinates(coordinates), _color(color) {}

string Shape::id() const {
    return _id;
}

vector<TwoDimensionalCoordinate*>  Shape::coordinates() const {
    return _coordinates;
}

string Shape::color() const {
    return _color;
}
    
void Shape::addShape(Shape *shape) {
    throw string("Only compound shape can add shape!");
}

void Shape::deleteShapeById(string id) {
    throw string("Only compound shape can delete shape!");
}

Shape* Shape::getShapeById(string id) {
    throw string("Only compound shape can get shape!");
}

Iterator* Shape::createIterator() {
    return new NullIterator();
}

Shape::~Shape() {}