#ifndef TWO_DIMENSIONAL_VECTOR_H
#define TWO_DIMENSIONAL_VECTOR_H

#include <math.h> 

using namespace std;

class TwoDimensionalVector{
	public:
	TwoDimensionalVector(double x, double y): _x(x), _y(y) {}

	double getX() {
		return _x;
	}

	double getY() {
		return _y;
	}

	double length() {
		// sqrt(pow(_x, 2) + pow(_y, 2));
		return sqrt(pow(_x, 2) + pow(_y, 2));
	}

	double dot(TwoDimensionalVector* vector) {
		return vector->getX() * _x + vector->getY() * _y;
	}

	double cross(TwoDimensionalVector* vector) {
		return _x * vector->getY() - _y * vector->getX();
	}

	TwoDimensionalVector* subtract(TwoDimensionalVector* vector) {
		return new TwoDimensionalVector(_x - vector->getX(), _y - vector->getY());
	}

	private:
	double _x;
	double _y;
};

#endif
