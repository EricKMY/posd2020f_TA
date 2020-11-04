#ifndef SHAPE_ITERATOR_H
#define SHAPE_ITERATOR_H

#include "iterator.h"

template<class ForwardIterator>
class ShapeIterator : public Iterator {
public:

    ShapeIterator(ForwardIterator begin, ForwardIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() {
        _current = _begin;
    }

    void next() {
        if(isDone()) {
            throw std::string("Moving past the end!");
        }
        ++_current;
    }

    bool isDone() const {
      return _current == _end;
    }

    Shape* currentItem() const {
        if(isDone()){
            throw std::string("No current item!");
        }
        return *_current;
    }

private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};

#endif