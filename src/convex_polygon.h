#ifndef CONVEX_POLYGON_H
#define CONVEX_POLYGON_H

#include "measurable.h"
#include "two_dimensional_vector.h"
#include <vector>

using namespace std;

class ConvexPolygon : Measurable{
    public: 
		ConvexPolygon(vector<TwoDimensionalVector> vectors);
};

#endif
