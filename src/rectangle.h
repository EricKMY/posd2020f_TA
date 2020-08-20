#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include <string>
#include "shape.h"

using namespace std;

class Rectangle : public Shape{
    public: 
		Rectangle(double length, double width): _length(length), _width(width) {
      if(_length <= 0 || _width <= 0) {
        throw string("this is not a rectangle!");
      }
    }

    double area() const {
      return _length * _width;
    }

    double perimeter() const {
      return 2 * (_length + _width);
    }
    
    string info() const {
      char result[100];
      sprintf(result, "Rectangle (%.3f, %.3f)", _length, _width);
      return result;
    }

    private:
    double _length;
    double _width;
};

#endif
