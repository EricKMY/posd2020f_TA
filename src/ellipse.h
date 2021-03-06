#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <math.h>
#include "shape.h"

class Ellipse : public Shape {
	public:
	Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes): Shape(id), _semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
		checkShapeIsValid();
	}

	Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color): Shape(id, color), _semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
		checkShapeIsValid();
	}

	double area() const {
		return _semiMajorAxes * _semiMinorAxes * M_PI;
	}

	double perimeter() const {
		return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
	}

	std::string info() const {
		char info[100];
		sprintf(info, "Ellipse (%.3f, %.3f)", _semiMajorAxes, _semiMinorAxes);
		return info;
	}

	std::string type() const {
		return "Ellipse";
	}

	void accept(Visitor* visitor) {
		visitor->visit(this);
	}

	double semiMajorAxes() const {
		return _semiMajorAxes;
	}

	double semiMinorAxes() const {
		return _semiMinorAxes;
	}

private:
	double _semiMajorAxes, _semiMinorAxes;

	void checkShapeIsValid() const {
		if(_semiMajorAxes <= 0 || _semiMinorAxes <= 0 || _semiMajorAxes < _semiMinorAxes) {
			throw std::string("This is not an ellipse!");
		}
    }
};

#endif
