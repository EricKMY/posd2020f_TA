#ifndef COMPOUND_SHAPE_H
#define COMPOUND_SHAPE_H

#include <string>
#include <list>
#include "shape.h"
#include "shape_iterator.h"

using namespace std;

class CompoundShape : public Shape {
public: 
  CompoundShape(string id, list<Shape*>* shapes): Shape(id, "transparent"), _shapes(shapes) {
    checkShapeIsValid();
  }

  double area() const {
    double area = 0;
    for(list<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      area += (*it)->area();
    }
    return area;
  }

  double perimeter() const {
    double perimeter = 0;
    for(list<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      perimeter += (*it)->perimeter();
    }
    return perimeter;
  }
    
  string info() const {
    string info = "Compound Shape {";
    for(list<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      info += (*it)->info() + ", ";
    }
    info.erase(info.end()-2, info.end());
    return info + "}";
  }

  string type() const {
    return "Compound Shape";
  }

  void addShape(Shape *shape) const {
    _shapes->push_back(shape);
  }

  void deleteShapeById(string id) const {
    for(list<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      if((*it)->id() == id) {
        _shapes->erase(it);
        return;
      }
      try {
        (*it)->deleteShapeById(id);
        return;
      }catch(string e) {
        continue;
      }
    }
    throw string("Expected delete shape but shape not found");
  }

  Shape* getShapeById(string id) const {
    for(list<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
        if((*it)->id() == id) {
          return *it;
        }
        try {
          return (*it)->getShapeById(id);
        }catch(string e) {
          continue;
        }
    }
    throw string("Expected get shape but shape not found");
  }

  Iterator * createIterator() const {
    return new ShapeIterator<list<Shape*>::iterator>(_shapes->begin(), _shapes->end());
  }

private:
  list<Shape*>* _shapes;

  void checkShapeIsValid() {
    if(_shapes->empty()) {
      throw string("This is not a compound shape!");
    }
  }
};

#endif