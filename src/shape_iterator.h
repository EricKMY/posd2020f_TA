#ifndef SHAPE_ITERATOR_H
#define SHAPE_ITERATOR_H

#include <string>
#include "iterator.h"

using namespace std;

template<class RandomAccessIterator>
class ShapeIterator : public Iterator {
public:

    ShapeIterator(RandomAccessIterator begin, RandomAccessIterator end): _begin(begin), _end(end) {
        first();
    }

    void first() {
        _current = _begin;
    }

    Shape* currentItem(){
        if(isDone()){
            throw string("No current item!");
        }
        return *_current;
    }

    void next() {
        if(isDone()){
            throw string("Moving past the end!");
        }
        ++_current;
    }

    bool isDone(){
      return _current == _end;
    }

private:
    RandomAccessIterator _begin;
    RandomAccessIterator _end;
    RandomAccessIterator _current;
};

#endif