#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H

#include "iterator.h"

class NullIterator : public Iterator {
    public:
    void first() {
        throw std::string("no child member!");
    }

    Shape* currentItem(){
        throw std::string("no child member!");
    }

    void next() {
        throw std::string("no child member!");
    }
    bool isDone(){
      return true;
    }
};

#endif