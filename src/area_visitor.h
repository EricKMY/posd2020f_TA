#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H

#include <math.h>
#include "visitor.h"
#include "iterator.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "compound_shape.h"

class AreaVisitor : public Visitor {
public:
    AreaVisitor(): _area(0) {}

    void visit(Ellipse* ellipse) {
        _area += ellipse->semiMajorAxes() * ellipse->semiMinorAxes() * M_PI;
    }

    void visit(Triangle* triangle) {
        _area += fabs(
                triangle->coordinates()[0]->getX() * triangle->coordinates()[1]->getY()
              + triangle->coordinates()[1]->getX() * triangle->coordinates()[2]->getY() 
              + triangle->coordinates()[2]->getX() * triangle->coordinates()[0]->getY() 
              - triangle->coordinates()[0]->getX() * triangle->coordinates()[2]->getY() 
              - triangle->coordinates()[1]->getX() * triangle->coordinates()[0]->getY() 
              - triangle->coordinates()[2]->getX() * triangle->coordinates()[1]->getY()) / 2;
    }

    void visit(Rectangle* rectangle) {
        _area += fabs(
                rectangle->coordinates()[0]->getX() * rectangle->coordinates()[1]->getY()
              + rectangle->coordinates()[1]->getX() * rectangle->coordinates()[2]->getY()
              + rectangle->coordinates()[2]->getX() * rectangle->coordinates()[3]->getY()
              + rectangle->coordinates()[3]->getX() * rectangle->coordinates()[0]->getY()
              - rectangle->coordinates()[0]->getX() * rectangle->coordinates()[3]->getY()
              - rectangle->coordinates()[1]->getX() * rectangle->coordinates()[0]->getY()
              - rectangle->coordinates()[2]->getX() * rectangle->coordinates()[1]->getY()
              - rectangle->coordinates()[3]->getX() * rectangle->coordinates()[2]->getY()) / 2;
    }

    void visit(CompoundShape* compoundShape) {
        Iterator* it = compoundShape->createIterator();
        for(it->first(); !it->isDone(); it->next()) {
            it->currentItem()->accept(this);
        }
    }

    double area() const {
        return _area;
    }

private:
    double _area;
};


#endif