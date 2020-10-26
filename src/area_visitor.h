#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H

#include "visitor.h"

class AreaVisitor : public Visitor {
public:
    AreaVisitor();

    void visit(const Ellipse* ellipse);

    void visit(const Triangle* triangle);

    void visit(const Rectangle* rectangle);

    void visit(const CompoundShape* compoundShape);

    string result() const;

private:
    double _area;
};


#endif