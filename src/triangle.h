#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "measurable.h"
#include "two_dimensional_vector.h"
#include <vector>

using namespace std;

class Triangle : Measurable{
    public: 
		Triangle(vector<TwoDimensionalVector> vectors);
};

#endif
