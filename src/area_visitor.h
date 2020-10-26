#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H

#include "visitor.h"

class AreaVisitor : public Visitor {
public:
    AreaVisitor();

    void visit(Ellipse* ellipse);

    void visit(Triangle* triangle);

    void visit(Rectangle* rectangle);

    void visit(CompoundShape* compoundShape);

    string result() const;
private:
    double _area;
};


#endif