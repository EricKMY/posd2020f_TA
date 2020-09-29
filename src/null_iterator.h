#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

#include "iterator.h"

class NullIterator : public Iterator {
    public:
    void first() {
        throw std::string("No child member!");
    }

    Shape* currentItem(){
        throw std::string("No child member!");
    }

    void next() {
        throw std::string("No child member!");
    }
    bool isDone(){
      return true;
    }
};

#endif