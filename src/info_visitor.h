#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include "visitor.h"

class InfoVisitor : public Visitor {
public:
    InfoVisitor();

    void visit(const Ellipse* ellipse);

    void visit(const Triangle* triangle);

    void visit(const Rectangle* rectangle);

    void visit(const CompoundShape* compoundShape);

    string result() const;

private:
    string _info;
};


#endif