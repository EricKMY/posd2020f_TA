#include "info_visitor.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "compound_shape.h"

InfoVisitor::InfoVisitor() {}

void InfoVisitor::visit(const Ellipse* ellipse) {
    char info[100];
    sprintf(info, "Ellipse (%.3f, %.3f)", ellipse->semiMajorAxes(), ellipse->semiMinorAxes());
    _info = info;
}

void InfoVisitor::visit(const Triangle* triangle) {
    char info[100];
    sprintf(info, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
        triangle->coordinates()[0]->getX(), triangle->coordinates()[0]->getY(),
        triangle->coordinates()[1]->getX(), triangle->coordinates()[1]->getY(),
        triangle->coordinates()[2]->getX(), triangle->coordinates()[2]->getY());

    _info = info;
}

void InfoVisitor::visit(const Rectangle* rectangle) {
    char info[100];
    sprintf(info, "Rectangle (%.3f, %.3f)", rectangle->length(), rectangle->width());

    _info = info;
}
void InfoVisitor::visit(const CompoundShape* compoundShape) {
    string info = "Compound Shape {";
    Iterator *it = compoundShape->createIterator();

    for(it->first();!it->isDone();it->next()) {
        it->currentItem()->accept(this);
        info += _info  + ", ";
    }
    info.erase(info.end()-2, info.end());
    
    _info = info + "}";
}

string InfoVisitor::result() const { return _info; }