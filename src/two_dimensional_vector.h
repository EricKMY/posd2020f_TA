#ifndef TWO_DIMENSIONAL_VECTOR_H
#define TWO_DIMENSIONAL_VECTOR_H

using namespace std;

class TwoDimensionalVector{
	public:
	TwoDimensionalVector(int x, int y);
	int getX();
	int getY();
	double length();
	int dot(TwoDimensionalVector vector);
	int cross(TwoDimensionalVector vector);
	TwoDimensionalVector subtract(TwoDimensionalVector vector);
};

#endif
