#ifndef TWO_DIMENSIONAL_VECTOR_H
#define TWO_DIMENSIONAL_VECTOR_H

#include <math.h> 

using namespace std;

class TwoDimensionalVector{
	public:
	TwoDimensionalVector(int x, int y): _x(x), _y(y) {}

	int getX() {
		return _x;
	}

	int getY() {
		return _y;
	}

	double length() {
		// sqrt(pow(_x, 2) + pow(_y, 2));
		return sqrt(pow(_x, 2) + pow(_y, 2));
	}

	int dot(TwoDimensionalVector* vector) {
		return vector->getX() * _x + vector->getY() * _y;
	}

	int cross(TwoDimensionalVector* vector) {
		return _x * vector->getY() - _y * vector->getX();
	}

	TwoDimensionalVector* subtract(TwoDimensionalVector* vector) {
		return new TwoDimensionalVector(_x - vector->getX(), _y - vector->getY());
	}

	private:
	int _x;
	int _y;
};

#endif
