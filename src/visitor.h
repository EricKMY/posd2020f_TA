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
    virtual void visit(const Ellipse* ellipse) = 0;

    virtual void visit(const Triangle* triangle) = 0;

    virtual void visit(const Rectangle* rectangle) = 0;

    virtual void visit(const CompoundShape* compoundShape) = 0;

    virtual string result() const = 0;
};

#endif