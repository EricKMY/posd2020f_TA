#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include "shape.h"
#include "../src/two_dimensional_coordinate.h"

using namespace std;

class Triangle : public Shape{
public: 

  Triangle(string id, vector<TwoDimensionalCoordinate*> vectors): Shape(id), _vectors(vectors){
      checkShapeIsValid();
  }

  Triangle(string id, vector<TwoDimensionalCoordinate*> vectors, string color): Shape(id, color), _vectors(vectors){
      checkShapeIsValid();
  }
  
  double area() const {
    return fabs(
            _vectors[0]->getX() * _vectors[1]->getY()
              + _vectors[1]->getX() * _vectors[2]->getY() 
              + _vectors[2]->getX() * _vectors[0]->getY() 
              - _vectors[0]->getX() * _vectors[2]->getY() 
              - _vectors[1]->getX() * _vectors[0]->getY() 
              - _vectors[2]->getX() * _vectors[1]->getY()) / 2;
  }

  double perimeter() const {
    return sqrt(pow(_vectors[0]->getX() - _vectors[1]->getX(), 2) + pow(_vectors[0]->getY() - _vectors[1]->getY(), 2))
          + sqrt(pow(_vectors[0]->getX() - _vectors[2]->getX(), 2) + pow(_vectors[0]->getY() - _vectors[2]->getY(), 2)) 
          + sqrt(pow(_vectors[2]->getX() - _vectors[1]->getX(), 2) + pow(_vectors[2]->getY() - _vectors[1]->getY(), 2));
  }
  
  string info() const {
    char info[100];
    sprintf(info, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
                              _vectors[0]->getX(), _vectors[0]->getY(),
                              _vectors[1]->getX(), _vectors[1]->getY(),
                              _vectors[2]->getX(), _vectors[2]->getY());
    return info;
  }

private:
  vector<TwoDimensionalCoordinate*> _vectors;

  void checkShapeIsValid() {
    if(_vectors.size() != 3) {
      throw string("This is not a triangle!");
    }else if(area() <= 0) {
      throw string("This is not a triangle!");
    }
  }
};

#endif
