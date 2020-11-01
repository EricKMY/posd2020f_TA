#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include "visitor.h"
#include "iterator.h"
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "compound_shape.h"

class InfoVisitor : public Visitor {
public:
    void visit(Ellipse* ellipse) {
        char info[100];
        sprintf(info, "Ellipse (%.3f, %.3f)", ellipse->semiMajorAxes(), ellipse->semiMinorAxes());
        _info = info;
    }

    void visit(Triangle* triangle) {
        char info[100];
        sprintf(info, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
            triangle->coordinates()[0]->getX(), triangle->coordinates()[0]->getY(),
            triangle->coordinates()[1]->getX(), triangle->coordinates()[1]->getY(),
            triangle->coordinates()[2]->getX(), triangle->coordinates()[2]->getY());

        _info = info;
    }

    void visit(Rectangle* rectangle) {
        char info[100];
        sprintf(info, "Rectangle (%.3f, %.3f)", rectangle->length(), rectangle->width());

        _info = info;
    }

    void visit(CompoundShape* compoundShape) {
        string info = "Compound Shape {";
        Iterator *it = compoundShape->createIterator();

        for(it->first();!it->isDone();it->next()) {
            it->currentItem()->accept(this);
            info += _info  + ", ";
        }
        info.erase(info.end()-2, info.end());
        
        _info = info + "}";
    }

    string info() const {
        return _info;
    }

private:
    string _info;
};


#endif