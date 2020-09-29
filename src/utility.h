#ifndef UTILITY_H
#define UTILITY_H

using namespace std;

Shape* getShapeById(Shape* shape, string id) {
    Iterator *it = shape->createIterator();

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
vector<Shape*> filterShape(Shape *shape, Filter filter) {
    vector<Shape*> results = {};
    Iterator *it = shape->createIterator();

    if(filter(shape)) {
        results.push_back(shape);
    }

    try {
        it->first();
    }catch(string e) {
        return results;
    }

    while(!it->isDone()) {
        vector<Shape*> shapes = filterShape(it->currentItem(), filter);
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
        return shape->color() == _color;
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
