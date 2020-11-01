#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Ellipse;
class Triangle;
class Rectangle;
class CompoundShape;

using namespace std;

class Visitor {
public:
    virtual void visit(Ellipse* ellipse) = 0;

    virtual void visit(Triangle* triangle) = 0;

    virtual void visit(Rectangle* rectangle) = 0;

    virtual void visit(CompoundShape* compoundShape) = 0;
};

#endif