#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include <vector>
#include <string>
#include <vector>
#include "shape.h"

using namespace std;

class ComplexShape : public Shape{
    public: 
    ComplexShape(vector<Shape*> shapes,string id):Shape(id),_shapes(shapes){}

    double area() const { return 0; }

    double perimeter() const { return 0; }
    
    string type() const {
      return "complex shape";
    }

    private:
    vector<Shape*> _shapes;

};

#endif
