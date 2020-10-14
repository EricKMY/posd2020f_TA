#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <vector>
#include "iterator.h"
#include "null_iterator.h"
#include "two_dimensional_coordinate.h"
#include "visitor.h"

using namespace std;

class Shape{
public:
        Shape(string id, vector<TwoDimensionalCoordinate*> coordinates);

        Shape(string id, vector<TwoDimensionalCoordinate*> coordinates, string color);

        virtual string id() const;

        virtual vector<TwoDimensionalCoordinate*> coordinates() const;

        virtual string color() const;

        virtual double area() const = 0;

        virtual double perimeter() const = 0;
  
        virtual string info() const = 0;
    
        virtual string type() const = 0;

        // virtual void move(double x, double y) = 0;

        virtual void accept(Visitor* v) = 0;

        virtual void addShape(Shape* shape);

        virtual void deleteShapeById(string id);

        virtual Shape* getShapeById(string id);
        
        virtual Iterator* createIterator();

        virtual ~Shape();

private:
        string _id;
        string _color;
        vector<TwoDimensionalCoordinate*> _coordinates;
};

#endif