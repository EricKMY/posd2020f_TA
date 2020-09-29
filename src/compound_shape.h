#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include <string>
#include <vector>
#include "shape.h"

using namespace std;

class CompoundShape : public Shape {
  class CompoundShapeIterator : public Iterator {
  public:
    CompoundShapeIterator(CompoundShape *s): _s(s) {}

    void first() {
      _current = _s->_shapes->begin();
    }

    Shape * currentItem() {
      if(isDone()){
        throw std::string("No current item!");
      }else{
        return *_current;
      }
    }

    void next() {
      if(isDone()){
        throw std::string("Moving past the end!");
      }else{
        ++_current;
      }
    }

    bool isDone() {
      return _current == _s->_shapes->end();
    }

  private:
    CompoundShape *_s;
    vector<Shape*>::iterator _current;
  };

public: 
  CompoundShape(string id, vector<Shape*>* shapes): Shape(id), _shapes(shapes) {
    checkShapeIsValid();
  }

  void checkShapeIsValid() {
    if(_shapes->empty()) {
      throw string("This is not a compound shape!");
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
    string info = "Compound Shape {";
    for(vector<Shape*>::iterator it = _shapes->begin(); it != _shapes->end(); ++it) {
      info += (*it)->info() + ", ";
    }
    info.erase(info.end()-2, info.end());
    return info + "}";
  }

  string color() const {
    throw string("Compound shape don't have single color");
  }

  string type() const {
    return "Compound Shape";
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
    throw string("Expected delete shape but shape not found");
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
    throw string("Expected get shape but shape not found");
  }

  Iterator * createIterator() {
    return new CompoundShapeIterator(this);
  }

private:
  vector<Shape*>* _shapes;
};

#endif