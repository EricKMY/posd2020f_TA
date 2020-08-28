#ifndef COMPLEX_SHAPE_H
#define COMPLEX_SHAPE_H

#include <vector>
#include <string>
#include <vector>
#include "shape.h"

using namespace std;

class ComplexShape : public Shape{
    public: 
    ComplexShape(string id, vector<Shape*> shapes):Shape(id),_shapes(shapes){}

    double area() const { return 0; }

    double perimeter() const { return 0; }
    
    string info() const {
      // char info[100];
      // sprintf(info, "Ellipse (%.3f, %.3f)", _semiMajorAxes, _semiMinorAxes);
      // return info;
	  }

    private:
    vector<Shape*> _shapes;

};

#endif
