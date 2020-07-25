#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape{
	public:
        virtual double getArea() const = 0;
        virtual double getPerimeter() const = 0;
        virtual string getType() const = 0;
};

#endif