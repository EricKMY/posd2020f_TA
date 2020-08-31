#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
// #include <vector>
#include "./shape.h"
// #include "two_dimensional_coordinate.h"

using namespace std;

class Rectangle : public Shape {
    public: 
		Rectangle(string id, double length, double width): Shape(id), _length(length), _width(width) {
      if(_length <= 0 || _width <= 0) {
        throw string("This is not a rectangle!");
      }
    }

    double area() const {
      return _length * _width;
    }

    double perimeter() const { return (_length + _width) * 2; }
    
    string info() const {
      char info[100];
      sprintf(info, "Rectangle (%.3f, %.3f)", _length, _width);
      return info;
    }

    private:
    double _length, _width;
};

#endif
