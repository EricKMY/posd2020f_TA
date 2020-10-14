#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include "shape.h"

using namespace std;

class Triangle : public Shape{
public: 

  Triangle(string id, vector<TwoDimensionalCoordinate*> coordinates): Shape(id, coordinates) {
      checkShapeIsValid();
  }

  Triangle(string id, vector<TwoDimensionalCoordinate*> coordinates, string color): Shape(id, coordinates, color) {
      checkShapeIsValid();
  }
  
  double area() const {
    return fabs(coordinates()[0]->getX() * coordinates()[1]->getY()
              + coordinates()[1]->getX() * coordinates()[2]->getY() 
              + coordinates()[2]->getX() * coordinates()[0]->getY() 
              - coordinates()[0]->getX() * coordinates()[2]->getY() 
              - coordinates()[1]->getX() * coordinates()[0]->getY() 
              - coordinates()[2]->getX() * coordinates()[1]->getY()) / 2;
  }

  double perimeter() const {
    return  sqrt(pow(coordinates()[0]->getX() - coordinates()[1]->getX(), 2) + pow(coordinates()[0]->getY() - coordinates()[1]->getY(), 2))
          + sqrt(pow(coordinates()[1]->getX() - coordinates()[2]->getX(), 2) + pow(coordinates()[1]->getY() - coordinates()[2]->getY(), 2)) 
          + sqrt(pow(coordinates()[2]->getX() - coordinates()[0]->getX(), 2) + pow(coordinates()[2]->getY() - coordinates()[0]->getY(), 2));
  }
  
  string info() const {
    char info[100];
    sprintf(info, "Triangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
                              coordinates()[0]->getX(), coordinates()[0]->getY(),
                              coordinates()[1]->getX(), coordinates()[1]->getY(),
                              coordinates()[2]->getX(), coordinates()[2]->getY());
    return info;
  }

  string type() const {
		return "Triangle";
	}

  void accept(Visitor* visitor) {
		visitor->visit(this);
	}

private:
  void checkShapeIsValid() {
    if(coordinates().size() != 3) {
      throw string("This is not a triangle!");
    }else if(area() <= 0) {
      throw string("This is not a triangle!");
    }
  }
};

#endif
