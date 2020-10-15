#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <deque>
#include "iterator.h"
#include "shape.h"

using namespace std;

Shape* getShapeById(Shape* shape, string id) {
    Iterator* it = shape->createIterator();

    try {
        it->first();
    }catch(string e) {
        throw string("Only compound shape can get shape!");
    }

    while(!it->isDone()) {
        if(it->currentItem()->id() == id) {
            return it->currentItem();
        }
        try{
            return getShapeById(it->currentItem(), id);
        }catch(string e) {}
        it->next();
    }

    throw string("Expected get shape but shape not found");
}

template <class Filter>
deque<Shape*> filterShape(Shape *shape, Filter filter) {
    deque<Shape*> results = {};
    Iterator* it = shape->createIterator();

    try {
        it->first();
    }catch(string e) {
        throw string("Only compound shape can filter shape!");
    }

    while(!it->isDone()) {
        deque<Shape*> shapes = {};
        if(filter(it->currentItem())) {
            results.push_back(it->currentItem());
        }
        try {
            shapes = filterShape(it->currentItem(), filter);
        }catch(string e) {}

        results.insert(results.end(), shapes.begin(), shapes.end());
        it->next();
    }

    return results;
}

class AreaFilter {
public:
    AreaFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator() (Shape *shape) {
        return shape->area() <= _upperBound && shape->area() >= _lowerBound;
    }

private:
    double _upperBound;
    double _lowerBound;
};

class PerimeterFilter {
public:
    PerimeterFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator() (Shape *shape) {
        return shape->perimeter() <= _upperBound && shape->perimeter() >= _lowerBound;
    }

private:
    double _upperBound;
    double _lowerBound;
};

class ColorFilter {
public:
    ColorFilter(string color): _color(color) {}

    bool operator() (Shape *shape) {
        try {
            return shape->color() == _color;
        }catch(string e) {}
        
        return false;
    }

private:
    string _color;
};

class TypeFilter {
public:
    TypeFilter(string type):_type(type) {}

    bool operator() (Shape *shape) {
        return shape->type() == _type;
    }

private:
    string _type;
};

#endif