#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
#include <string>
#include <stdio.h>
#include "shape.h"

using namespace std;

class Ellipse : public Shape {
	public:
	Ellipse(double semiMajorAxes, double semiMinorAxes):_semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
		if(_semiMajorAxes <= 0 || _semiMinorAxes <= 0) {
        	throw string("This is not an ellipse!");
      	}

		if(_semiMajorAxes < _semiMinorAxes) {
			throw string("This is not an ellipse!");
		}
	}

	double area() const {
		return _semiMajorAxes * _semiMinorAxes * M_PI;
	}

	double perimeter() const {
		return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
	}

	string info() const {
		char info[100];
		sprintf(info, "Ellipse (%.3f, %.3f)", _semiMajorAxes, _semiMinorAxes);
		return info;
	}

	private:
	double _semiMajorAxes, _semiMinorAxes;
};

#endif
