#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <deque>
#include "iterator.h"
#include "shape.h"

Shape* getShapeById(Shape* shape, std::string id) {
    Iterator* it = shape->createIterator();

    try {
        it->first();
    }catch(std::string e) {
        throw std::string("Only compound shape can get shape!");
    }

    while(!it->isDone()) {
        if(it->currentItem()->id() == id) {
            return it->currentItem();
        }
        try{
            return getShapeById(it->currentItem(), id);
        }catch(std::string e) {}
        it->next();
    }

    throw std::string("Expected get shape but shape not found");
}

template <class Filter>
std::deque<Shape*> filterShape(Shape *shape, Filter filter) {
    std::deque<Shape*> results = {};
    Iterator* it = shape->createIterator();

    try {
        it->first();
    }catch(std::string e) {
        throw std::string("Only compound shape can filter shape!");
    }

    while(!it->isDone()) {
        std::deque<Shape*> shapes = {};
        if(filter(it->currentItem())) {
            results.push_back(it->currentItem());
        }
        try {
            shapes = filterShape(it->currentItem(), filter);
        }catch(std::string e) {}

        results.insert(results.end(), shapes.begin(), shapes.end());
        it->next();
    }

    return results;
}

class AreaFilter {
public:
    AreaFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator() (Shape *shape) const {
        return shape->area() <= _upperBound && shape->area() >= _lowerBound;
    }

private:
    double _upperBound;
    double _lowerBound;
};

class PerimeterFilter {
public:
    PerimeterFilter(double upperBound, double lowerBound): _upperBound(upperBound), _lowerBound(lowerBound) {}

    bool operator() (Shape *shape) const {
        return shape->perimeter() <= _upperBound && shape->perimeter() >= _lowerBound;
    }

private:
    double _upperBound;
    double _lowerBound;
};

class ColorFilter {
public:
    ColorFilter(std::string color): _color(color) {}

    bool operator() (Shape *shape) const {
        return shape->color() == _color;
    }

private:
    std::string _color;
};

class TypeFilter {
public:
    TypeFilter(std::string type):_type(type) {}

    bool operator() (Shape *shape) const {
        return shape->type() == _type;
    }

private:
    std::string _type;
};

#endif