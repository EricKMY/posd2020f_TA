#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

#include "shape.h"
#include "two_dimensional_vector.h"
#include <vector>

using namespace std;

class ConvexPolygon : Shape{
    public: 
		ConvexPolygon(vector<TwoDimensionalVector> vectors);
};

#endif
