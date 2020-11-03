#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

#include "iterator.h"

using namespace std;

class NullIterator : public Iterator {
public:
    void first() {
        throw string("No child member!");
    }

    void next() {
        throw string("No child member!");
    }

    bool isDone() const {
      return true;
    }

    Shape* currentItem() const {
        throw string("No child member!");
    }
};

#endif