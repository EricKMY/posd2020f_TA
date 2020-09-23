#ifndef SHAPE_H
#define SHAPE_H

using namespace std;

class Shape {
public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual string info() const = 0;
};

#endif