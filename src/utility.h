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

    for(;!it->isDone(); it->next()){
        if(it->currentItem()->id() == id) {
            return it->currentItem();
        }
        try{
            return getShapeById(it->currentItem(), id);
        }catch(string e) {}
    }
    throw string("Expected get shape but shape not found");
}

template <class Compare>
vector<Shape*> filterShape(Shape *shape, Compare comp) {
    vector<Shape*> results = {};

    Iterator *it = shape->createIterator();
    try {
        it->first();
    }catch(string e) {

        if(comp(shape)) {
            results.push_back(shape);
        }
        return results;
    }

    if(comp(shape)) {
        results.push_back(shape);
    }

    for(;!it->isDone(); it->next()){
        vector<Shape*> _v = filterShape(it->currentItem(), comp);
        results.insert(results.end(), _v.begin(), _v.end());
    }

    return results;
}

class AreaFilter {
    public:
    AreaFilter(double upperBound, double lowerBound):_upperBound(upperBound),_lowerBound(lowerBound) {}

    bool operator() (Shape *shape) {
        return shape->area() <= _upperBound && shape->area() >= _lowerBound;
    }

    private:
    double _upperBound;
    double _lowerBound;
};

class PerimeterFilter {
    public:
    PerimeterFilter(double upperBound, double lowerBound):_upperBound(upperBound),_lowerBound(lowerBound) {}

    bool operator() (Shape *shape) {
        return shape->perimeter() <= _upperBound && shape->perimeter() >= _lowerBound;
    }

    private:
    double _upperBound;
    double _lowerBound;
};

class ColorFilter {
    public:
    ColorFilter(string color):_color(color) {}

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
