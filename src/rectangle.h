#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "two_dimensional_coordinate.h"
#include <math.h>

class Rectangle : public Shape {
public: 
  Rectangle(std::string id, TwoDimensionalCoordinate *position, std::vector<TwoDimensionalCoordinate *> coordinates): Shape(id), _position(position), _coordinates(coordinates) {
    checkShapeIsValid();
  }

  Rectangle(std::string id, TwoDimensionalCoordinate *position, std::vector<TwoDimensionalCoordinate *> coordinates, std::string color): Shape(id, color), _position(position), _coordinates(coordinates) {
    checkShapeIsValid();
  }

  double area() const {
    double bottom_length = sqrt(pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2));
    double right_length = sqrt(pow(_coordinates[1]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[1]->getY() - _coordinates[2]->getY(), 2));

    return bottom_length * right_length;
  }

  double perimeter() const {
    double bottom_length = sqrt(pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2));
    double right_length = sqrt(pow(_coordinates[1]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[1]->getY() - _coordinates[2]->getY(), 2));

    return (bottom_length + right_length) * 2;
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

  TwoDimensionalCoordinate *_position;
  std::vector<TwoDimensionalCoordinate *> _coordinates;
  
  void checkShapeIsValid() const {
    double bottom_length = sqrt(pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2));
    double right_length = sqrt(pow(_coordinates[1]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[1]->getY() - _coordinates[2]->getY(), 2));
    double top_length = sqrt(pow(_coordinates[2]->getX() - _coordinates[3]->getX(), 2) + pow(_coordinates[2]->getY() - _coordinates[3]->getY(), 2));
    double left_length = sqrt(pow(_coordinates[3]->getX() - _coordinates[0]->getX(), 2) + pow(_coordinates[3]->getY() - _coordinates[0]->getY(), 2));

    if(bottom_length <= 0 || right_length <= 0 || top_length <=0 || left_length <= 0 || 
      bottom_length != top_length || right_length != left_length) {
      throw std::string("This is not a rectangle!");
    }
  }
};

#endif
