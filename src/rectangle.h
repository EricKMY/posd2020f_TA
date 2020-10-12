#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include <vector>
#include <math.h>
#include "shape.h"

using namespace std;

class Rectangle : public Shape {
public: 
  Rectangle(string id, vector<TwoDimensionalCoordinate*> coordinates): Shape(id, coordinates) {
    checkShapeIsValid();
  }

  Rectangle(string id, vector<TwoDimensionalCoordinate*> coordinates, string color): Shape(id, coordinates, color) {
    checkShapeIsValid();
  }

  double area() const {
    return fabs(coordinates()[0]->getX() * coordinates()[1]->getY()
              + coordinates()[1]->getX() * coordinates()[2]->getY()
              + coordinates()[2]->getX() * coordinates()[3]->getY()
              + coordinates()[3]->getX() * coordinates()[0]->getY()
              - coordinates()[0]->getX() * coordinates()[3]->getY()
              - coordinates()[1]->getX() * coordinates()[0]->getY() 
              - coordinates()[2]->getX() * coordinates()[1]->getY()
              - coordinates()[3]->getX() * coordinates()[2]->getY()) / 2;
  }

  double perimeter() const {
    return  sqrt(pow(coordinates()[0]->getX() - coordinates()[1]->getX(), 2) + pow(coordinates()[0]->getY() - coordinates()[1]->getY(), 2))
          + sqrt(pow(coordinates()[1]->getX() - coordinates()[2]->getX(), 2) + pow(coordinates()[1]->getY() - coordinates()[2]->getY(), 2)) 
          + sqrt(pow(coordinates()[2]->getX() - coordinates()[3]->getX(), 2) + pow(coordinates()[2]->getY() - coordinates()[3]->getY(), 2))
          + sqrt(pow(coordinates()[3]->getX() - coordinates()[0]->getX(), 2) + pow(coordinates()[3]->getY() - coordinates()[0]->getY(), 2));

  }
  
  string info() const {
    char info[100];
    sprintf(info, "Rectangle ([%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f], [%.3f, %.3f])",
                                      coordinates()[0]->getX(), coordinates()[0]->getY(),
                                      coordinates()[1]->getX(), coordinates()[1]->getY(),
                                      coordinates()[2]->getX(), coordinates()[2]->getY(),
                                      coordinates()[3]->getX(), coordinates()[3]->getY());
    return info;
  }

  string type() const {
		return "Rectangle";
	}

private:
  void checkShapeIsValid() {
    if(coordinates().size() != 4) {
      throw string("This is not a rectangle!");
    }
  }
};

#endif
