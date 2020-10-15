#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Iterator;

using namespace std;

class Shape{
public:
        Shape(string id);

        Shape(string id, string color);

        string id() const;

        string color() const;

        virtual double area() const = 0;

        virtual double perimeter() const = 0;
  
        virtual string info() const = 0;
    
        virtual string type() const = 0;

        virtual void addShape(Shape *shape) const;

        virtual void deleteShapeById(string id) const;

        virtual Shape* getShapeById(string id) const;
        
        virtual Iterator *createIterator() const;

        virtual ~Shape();

private:
        string _id;
        string _color;
};

#endif