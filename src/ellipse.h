#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <math.h>
#include <string>
#include <stdio.h>
#include "shape.h"

using namespace std;

class Ellipse : public Shape {
	public:
	Ellipse(string id, vector<TwoDimensionalCoordinate*> coordinates, double semiMajorAxes, double semiMinorAxes): Shape(id, coordinates), _semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
		checkShapeIsValid();
	}

	Ellipse(string id, vector<TwoDimensionalCoordinate*> coordinates, double semiMajorAxes, double semiMinorAxes, string color): Shape(id, coordinates, color), _semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
		checkShapeIsValid();
	}

	double area() const {
		return _semiMajorAxes * _semiMinorAxes * M_PI;
	}

	double perimeter() const {
		return 2 * M_PI * _semiMinorAxes + 4 * (_semiMajorAxes - _semiMinorAxes);
	}

	string info() const {
		char info[100];
		sprintf(info, "Ellipse ([%.3f, %.3f], %.3f, %.3f)", coordinates()[0]->getX(), coordinates()[0]->getY(), _semiMajorAxes, _semiMinorAxes);
		return info;
	}

	string type() const {
		return "Ellipse";
	}

private:
	double _semiMajorAxes, _semiMinorAxes;

	void checkShapeIsValid() {
		if(coordinates().size() != 1 || _semiMajorAxes <= 0 || _semiMinorAxes <= 0 || _semiMajorAxes < _semiMinorAxes) {
			throw string("This is not an ellipse!");
		}
    }
};

#endif
