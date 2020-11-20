#pragma once

#include <stack>
#include <vector>
#include <deque>
#include "../src/ellipse.h"
#include "../src/rectangle.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"

class ShapeBuilder {
public:
    void buildRectangle(std::string id, double length, double width) {
        _results.push(new Rectangle(id, length, width));
    }

    void buildEllipse(std::string id, double semiMajorAxes, double semiMinorAxes) {
        _results.push(new Ellipse(id, semiMajorAxes, semiMinorAxes));
    }

    void buildTriangle(std::string id, double x1, double y1, double x2, double y2, double x3, double y3) {
        std::vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(x1, y1));
        coordinates.push_back(new TwoDimensionalCoordinate(x2, y2));
        coordinates.push_back(new TwoDimensionalCoordinate(x3, y3));
        _results.push(new Triangle(id, coordinates));
    }

    void buildCompundShapeStart(std::string id) {
        Shape* s = new CompoundShape(id, {});
        _results.push(s);
    }

    void buildCompundShapeEnd() {
        Shape* s = _results.top();
        if(isEmptyCompoundShape(s)) {
            while(_results.size() != 0) {
                _results.pop();
                s->addShape(_results.top());
            }
        }
        _results.push(s);
    }

    std::stack<Shape*> getResult() {
        return _results;
    }

private:
    std::stack<Shape*> _results;

    bool isEmptyCompoundShape(Shape* s) {
        return dynamic_cast<CompoundShape*>(s) && s->createIterator()->isDone();
    }
};