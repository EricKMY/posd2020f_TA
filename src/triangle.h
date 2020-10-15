#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <deque>
#include <string>
#include <stdio.h>
#include "shape.h"
#include "../src/two_dimensional_coordinate.h"

using namespace std;

class Triangle : public Shape{
public: 

  Triangle(string id, deque<TwoDimensionalCoordinate*> coordinates): Shape(id), _coordinates(coordinates){
      checkShapeIsValid();
  }

  Triangle(string id, deque<TwoDimensionalCoordinate*> coordinates, string color): Shape(id, color), _coordinates(coordinates){
      checkShapeIsValid();
  }
  
  double area() const {
    return fabs(
            _coordinates[0]->getX() * _coordinates[1]->getY()
              + _coordinates[1]->getX() * _coordinates[2]->getY() 
              + _coordinates[2]->getX() * _coordinates[0]->getY() 
              - _coordinates[0]->getX() * _coordinates[2]->getY() 
              - _coordinates[1]->getX() * _coordinates[0]->getY() 
              - _coordinates[2]->getX() * _coordinates[1]->getY()) / 2;
  }

  double perimeter() const {
    return sqrt(pow(_coordinates[0]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[1]->getY(), 2))
          + sqrt(pow(_coordinates[0]->getX() - _coordinates[2]->getX(), 2) + pow(_coordinates[0]->getY() - _coordinates[2]->getY(), 2)) 
          + sqrt(pow(_coordinates[2]->getX() - _coordinates[1]->getX(), 2) + pow(_coordinates[2]->getY() - _coordinates[1]->getY(), 2));
  }
  
  string info() const {
    char info[100];
    sprintf(info, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
                              _coordinates[0]->getX(), _coordinates[0]->getY(),
                              _coordinates[1]->getX(), _coordinates[1]->getY(),
                              _coordinates[2]->getX(), _coordinates[2]->getY());
    return info;
  }

  string type() const {
		return "Triangle";
	}

private:
  deque<TwoDimensionalCoordinate*> _coordinates;

  void checkShapeIsValid() {
    if(_coordinates.size() != 3) {
      throw string("This is not a triangle!");
    }else if(area() <= 0) {
      throw string("This is not a triangle!");
    }
  }
};

#endif
