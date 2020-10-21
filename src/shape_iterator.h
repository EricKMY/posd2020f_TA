#ifndef SHAPE_ITERATOR_H
#define SHAPE_ITERATOR_H

#include <string>
#include "iterator.h"

using namespace std;

template<class InputIterator>
class ShapeIterator : public Iterator {
public:

    ShapeIterator(InputIterator begin, InputIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() {
        _current = _begin;
    }

    void next() {
        if(isDone()) {
            throw string("Moving past the end!");
        }
        ++_current;
    }

    bool isDone() const {
      return _current == _end;
    }

    Shape* currentItem() const {
        if(isDone()){
            throw string("No current item!");
        }
        return *_current;
    }

private:
    InputIterator _begin;
    InputIterator _end;
    InputIterator _current;
};

#endif