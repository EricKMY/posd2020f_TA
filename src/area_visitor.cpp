#include "area_visitor.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "compound_shape.h"

AreaVisitor::AreaVisitor(): _area(0) {}

void AreaVisitor::visit(Ellipse* ellipse) {
    _area = ellipse->semiMajorAxes() * ellipse->semiMinorAxes() * M_PI;
}

void AreaVisitor::visit(Triangle* triangle) {
    _area = fabs(
            triangle->coordinates()[0]->getX() * triangle->coordinates()[1]->getY()
              + triangle->coordinates()[1]->getX() * triangle->coordinates()[2]->getY() 
              + triangle->coordinates()[2]->getX() * triangle->coordinates()[0]->getY() 
              - triangle->coordinates()[0]->getX() * triangle->coordinates()[2]->getY() 
              - triangle->coordinates()[1]->getX() * triangle->coordinates()[0]->getY() 
              - triangle->coordinates()[2]->getX() * triangle->coordinates()[1]->getY()) / 2;
    
}

void AreaVisitor::visit(Rectangle* rectangle) {
    _area = rectangle->length() * rectangle->width();
}

void AreaVisitor::visit(CompoundShape* compoundShape) {
    double area = 0;
    Iterator *it = compoundShape->createIterator();

    for(it->first(); !it->isDone(); it->next()) {
        it->currentItem()->accept(this);
        area += _area;
    }

    _area = area;
}

string AreaVisitor::result() const {
    char result[100];
    sprintf(result, "%.3f", _area);
    return result;
}