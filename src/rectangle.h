#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include <string>
#include <stdio.h>
#include "shape.h"

using namespace std;
class Rectangle : public Shape {
public: 
  Rectangle(double length, double width): _length(length), _width(width) {
    if(_length <= 0 || _width <= 0) {
      throw string("This is not a rectangle!");
    }
  }

  double area() const {
    return _length * _width;
  }

  double perimeter() const {
    return 2 * (_length + _width);
  }
  
  string info() const {
    char info[100];
    sprintf(info, "Rectangle (%.3f, %.3f)", _length, _width);
    return info;
  }

private:
  double _length, _width;
};

#endif
