#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "two_dimensional_vector.h"
#include <vector>

using namespace std;

class Triangle : Shape{
    public: 
		Triangle(vector<TwoDimensionalVector> vectors);
};

#endif
