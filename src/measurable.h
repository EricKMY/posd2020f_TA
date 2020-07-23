#ifndef MEASURABLE_H
#define MEASURABLE_H


using namespace std;

class Measurable{
	public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual string toString() const = 0;
};

#endif