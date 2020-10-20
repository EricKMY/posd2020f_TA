#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include <string>
#include "visitor.h"


class InfoVisitor : public Visitor {
public:
    InfoVisitor();
    void visit(Ellipse* ellipse);
    void visit(Triangle* triangle);
    void visit(Rectangle* rectangle);
    void visit(CompoundShape* compoundShape);

    std::string info();
private:
    std::string _info;
};


#endif