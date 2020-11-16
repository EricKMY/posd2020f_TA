#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public: 
  Rectangle(std::string id, double length, double width): Shape(id), _length(length), _width(width) {
    checkShapeIsValid();
  }

  Rectangle(std::string id, double length, double width, std::string color): Shape(id, color), _length(length), _width(width) {
    checkShapeIsValid();
  }

  double area() const {
    return _length * _width;
  }

  double perimeter() const {
    return (_length + _width) * 2;
  }
  
  std::string info() const {
    char info[100];
    sprintf(info, "Rectangle (%.3f, %.3f)", _length, _width);
    return info;
  }

  std::string type() const {
		return "Rectangle";
	}

  void accept(Visitor* visitor) {
		visitor->visit(this);
	}

  double length() const {
    return _length;
  }

  double width() const {
    return _width;
  }

private:
  double _length, _width;

  void checkShapeIsValid() const {
    if(_length <= 0 || _width <= 0) {
      throw std::string("This is not a rectangle!");
    }
  }
};

#endif
