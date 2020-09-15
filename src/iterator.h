#ifndef ITERATOR_H
#define ITERATOR_H

class Shape;
class Iterator {
    public:
    virtual void first() = 0;
    virtual Shape* currentItem() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
};

#endif