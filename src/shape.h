#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using namespace std;

class Shape{
public:
        Shape(string id);

        Shape(string id, string color);

        virtual string id() const;

        virtual string color() const;

        virtual double area() const = 0;

        virtual double perimeter() const = 0;

        virtual string info() const = 0;

        virtual void addShape(Shape *shape);

        virtual void deleteShapeById(string id);

        virtual Shape* getShapeById(string id);

        virtual ~Shape();

private:
        string _id;
        string _color;
};

#endif