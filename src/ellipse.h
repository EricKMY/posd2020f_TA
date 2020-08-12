#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
#include "shape.h"

class Ellipse : public Shape {
	public:
	Ellipse(double semiMajorAxes, double semiMinorAxes):_semiMajorAxes(semiMajorAxes),_semiMinorAxes(semiMinorAxes){
		if(_semiMajorAxes <= 0 || _semiMinorAxes <= 0) {
        	throw string("this is not a ellipse!");
      	}
	}

	double area() const {
		return _semiMajorAxes * _semiMinorAxes * M_PI;
	}

	double perimeter() const {
		return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
	}

	string type() const {
		return "ellipse";
	}

	private:
	double _semiMajorAxes, _semiMinorAxes;
};

#endif
