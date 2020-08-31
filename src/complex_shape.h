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
    vector<Shape*>::iterator it = _shapes->begin();
    while(it != _shapes->end()) {
      area += (*it)->area();
      ++it;
    }
    return area;
  }

  double perimeter() const {
    double perimeter = 0;
    vector<Shape*>::iterator it = _shapes->begin();
    while(it != _shapes->end()) {
      perimeter += (*it)->perimeter();
      ++it;
    }
    return perimeter;
  }
    
  string info() const {
    string info = "Complex Shape {";
    vector<Shape*>::iterator it = _shapes->begin();
    while(it != _shapes->end()) {
      info += (*it)->info() + ", ";
      ++it;
    }
    info.erase(info.end()-2, info.end());
    return info + "}";
  }

  void addShape(Shape *shape) {
    _shapes->push_back(shape);
  }

  void deleteShapeById(string id) {
    if(getShapeByIdImpl(id) == nullptr) {
      throw string("expected delete shape but shape not found");
    };
    vector<Shape*>::iterator it = _shapes->begin();
    while(it != _shapes->end()) {
      if((*it)->id() == id) {
        _shapes->erase(it);
        break;
      }
      try {
        (*it)->deleteShapeById(id);
      }catch(string e) {}
      ++it;
    }
  }

  Shape* getShapeById(string id) {
    if(getShapeByIdImpl(id) == nullptr) {
      throw string("expected get shape but shape not found");
    };
    return getShapeByIdImpl(id);
  }

  private:
  vector<Shape*>* _shapes;

  Shape* getShapeByIdImpl(string id) {
    vector<Shape*>::iterator it = _shapes->begin();
    while(it != _shapes->end()) {
      if((*it)->id() == id) {
        return *it;
      }
      try {
        return (*it)->getShapeById(id);
      }catch(string e) {}
      ++it;
    }
    return nullptr;
  }
};

#endif