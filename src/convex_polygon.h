#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

#include <vector>
#include "shape.h"
#include "two_dimensional_vector.h"

using namespace std;

class ConvexPolygon : Shape{
    public: 
		ConvexPolygon(vector<TwoDimensionalVector*> vectors)_vectors(vector) {
        if(!isCovexPolygon(vectors)) {
            throw string("this is not a convexPolygon!");

        }
    }

    double area() const {
      return 
    }

    double perimeter() const {
    }
    
    string type() const {
      return "convexPolygon";
    }


    private:
    bool isCovexPolygon(vector<TwoDimensionalVector*> vectors) {
   
    }

    vector<TwoDimensionalVector*> _vectors;
};

#endif
