#include "shape.h"

using namespace std;

Shape::Shape(string id): _id(id){}

string Shape::id() const {
    return _id;
}
    
void Shape::addShape(Shape *shape) {
    throw string("Only complex shape can add shape!");
}

void Shape::deleteShapeById(string id) {
    throw string("Only complex shape can delete shape!");
}

Shape* Shape::getShapeById(string id) {
    throw string("Only complex shape can get shape!");
}

Shape::~Shape() {}