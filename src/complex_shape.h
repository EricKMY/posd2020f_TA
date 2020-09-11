#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include <string>
#include <vector>
#include "shape.h"

using namespace std;

class ComplexShape : public Shape {
  public: 
  ComplexShape(string id, vector<Shape*>* shapes): Shape(id), _shapes(shapes) {
    if(_shapes->empty()) {
      throw string("This is not a complexShape shape!");
    }
  }

  double area() const {
    double area = 0;
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      area += (*it)->area();
    }
    return area;
  }

  double perimeter() const {
    double perimeter = 0;
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      perimeter += (*it)->perimeter();
    }
    return perimeter;
  }
    
  string info() const {
    string info = "Complex Shape {";
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      info += (*it)->info() + ", ";
    }
    info.erase(info.end()-2, info.end());
    return info + "}";
  }

  void addShape(Shape *shape) {
    _shapes->push_back(shape);
  }

  void deleteShapeById(string id) {
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      if((*it)->id() == id) {
        _shapes->erase(it);
        return;
      }
      try {
        (*it)->deleteShapeById(id);
        return;
      }catch(string e) {}
    }
    throw string("expected delete shape but shape not found");
  }

  Shape* getShapeById(string id) {
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
        if((*it)->id() == id) {
          return *it;
        }
        try {
          return (*it)->getShapeById(id);
        }catch(string e) {}
    }
    throw string("expected get shape but shape not found");
  }

  private:
  vector<Shape*>* _shapes;
};

#endif