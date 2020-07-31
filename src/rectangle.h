#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <vector>
#include <string>
#include <vector>
#include "shape.h"
#include "two_dimensional_vector.h"

using namespace std;

class Rectangle : public Shape{
    public:
		Rectangle(vector<TwoDimensionalVector*> vectors, string id):Shape(id),_vectors(vectors){}

    double area() const { return 0; }

    double perimeter() const { return 0; }
    
    string type() const {
      return "rectangle";
    }

    private:
    vector<TwoDimensionalVector*> _vectors;

};

#endif
