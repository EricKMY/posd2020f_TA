#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "two_dimensional_coordinate.h"
#include <math.h>

class Rectangle : public Shape {
public: 
  Rectangle(std::string id,  std::vector<TwoDimensionalCoordinate*> coordinates): Shape(id), _coordinates(coordinates) {
    checkShapeIsValid();
  }

  Rectangle(std::string id, std::vector<TwoDimensionalCoordinate*> coordinates, std::string color): Shape(id, color), _coordinates(coordinates) {
    checkShapeIsValid();
  }

  double area() const {
    return fabs(_coordinates[0]->getX() * _coordinates[1]->getY()
              + _coordinates[1]->getX() * _coordinates[2]->getY()
              + _coordinates[2]->getX() * _coordinates[3]->getY()
              + _coordinates[3]->getX() * _coordinates[0]->getY()
              - _coordinates[0]->getX() * _coordinates[3]->getY() 
              - _coordinates[1]->getX() * _coordinates[0]->getY() 
              - _coordinates[2]->getX() * _coordinates[1]->getY()
              - _coordinates[3]->getX() * _coordinates[2]->getY()) / 2;
  }

  double perimeter() const {
    return  sqrt(pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2))
          + sqrt(pow(_coordinates[1]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[1]->getY() - _coordinates[2]->getY(), 2)) 
          + sqrt(pow(_coordinates[2]->getX() - _coordinates[3]->getX(), 2) + pow(_coordinates[2]->getY() - _coordinates[3]->getY(), 2))
          + sqrt(pow(_coordinates[3]->getX() - _coordinates[0]->getX(), 2) + pow(_coordinates[3]->getY() - _coordinates[0]->getY(), 2));
  }
  
  std::string info() const {
    char info[100];
    sprintf(info, "Rectangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
                              _coordinates[0]->getX(), _coordinates[0]->getY(),
                              _coordinates[1]->getX(), _coordinates[1]->getY(),
                              _coordinates[2]->getX(), _coordinates[2]->getY(),
                              _coordinates[3]->getX(), _coordinates[3]->getY());
    return info;
  }

  std::string type() const {
		return "Rectangle";
	}

  void accept(Visitor* visitor) {
		visitor->visit(this);
	}

  std::vector<TwoDimensionalCoordinate*> coordinates() {
    return _coordinates;
  }

private:
  std::vector<TwoDimensionalCoordinate*> _coordinates;
  
  void checkShapeIsValid() const {
    if(_coordinates.size() != 4 || isLengthEqualsZero()) {
      throw std::string("This is not a rectangle!");
    }
  }

  bool isLengthEqualsZero() const {
    return pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2) == 0 ||
           pow(_coordinates[1]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[1]->getY() - _coordinates[2]->getY(), 2) == 0 ||
           pow(_coordinates[2]->getX() - _coordinates[3]->getX(), 2) + pow(_coordinates[2]->getY() - _coordinates[3]->getY(), 2) == 0 ||
           pow(_coordinates[3]->getX() - _coordinates[0]->getX(), 2) + pow(_coordinates[3]->getY() - _coordinates[0]->getY(), 2) == 0 ;
  }
};

#endif
