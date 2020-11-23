#pragma once

#include <string>
#include <stack>
#include <list>
#include "ellipse.h"
#include "rectangle.h"
#include "triangle.h"
#include "compound_shape.h"

class ShapeBuilder {
public:
    ShapeBuilder(): _id(0) {}

    void buildRectangle(double length, double width) {
        _results.push(new Rectangle(std::to_string(++_id), length, width));
    }

    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        _results.push(new Ellipse(std::to_string(++_id), semiMajorAxes, semiMinorAxes));
    }

    void buildTriangle( double x1, double y1, double x2, double y2, double x3, double y3) {
        std::vector<TwoDimensionalCoordinate*> coordinates;
        coordinates.push_back(new TwoDimensionalCoordinate(x1, y1));
        coordinates.push_back(new TwoDimensionalCoordinate(x2, y2));
        coordinates.push_back(new TwoDimensionalCoordinate(x3, y3));
        _results.push(new Triangle(std::to_string(++_id), coordinates));
    }

    void buildCompoundShapeBegin() {
        _results.push(nullptr);
    }

    void buildCompoundShapeEnd() {
        std::list<Shape*> contents = {};
        while(_results.size() != 0) {
            if(_results.top() == nullptr)
                break;
            contents.push_back(_results.top());
            _results.pop();
        }
        _results.pop();
        _results.push(new CompoundShape(std::to_string(++_id), contents));
    }

    std::stack<Shape*> getResult() {
        return _results;
    }

private:
    int _id;
    std::stack<Shape*> _results;
};