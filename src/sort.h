#ifndef SORT_H
#define SORT_H

#include <string>
#include <algorithm>
#include <functional>
#include "shape.h"

using namespace std;

template <class RandomAccessIterator, class Compare>
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    quickSortImpl(first, last-1, comp);
}

template <class RandomAccessIterator, class Compare>
void quickSortImpl(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    if(first < last) {
        RandomAccessIterator pivot = divide(first, last, comp);
        quickSortImpl(first, pivot, comp);
        quickSortImpl(pivot+1, last, comp);
    }
}

template <class RandomAccessIterator, class Compare>
RandomAccessIterator divide(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {
    RandomAccessIterator pivot = first + (last - first) / 2;
    RandomAccessIterator i = first - 1;
    RandomAccessIterator j = last + 1;
    while(true) {
        do {
            i++;
        }while(comp(*i, *pivot));
        do {
            j--;
        }while(comp(*pivot, *j));
            if(i >= j) {
            return j;
        }
        swap(*i, *j);
    }
}

bool areaAscendingCompare(Shape *a, Shape *b) {
    return a->area() < b->area();
};

bool areaDescendingCompare(Shape *a, Shape *b) {
      return a->area() > b->area();
};

bool perimeterAscendingCompare(Shape *a, Shape *b) {
      return a->perimeter() < b->perimeter();
};

bool perimeterDescendingCompare(Shape *a, Shape *b) {
        return a->perimeter() > b->perimeter();
};

class AscendingCompare {
  public:
    AscendingCompare(string feature): _feature(feature) {}

    bool operator()(Shape *a, Shape *b) {
        if(_feature == "area"){
            return a->area() < b->area();
            
        }else if(_feature == "perimeter"){
            return a->perimeter() < b->perimeter();

        }
        return 0;
      }
  private:
    string _feature;
};

class DescendingCompare {
  public:
    DescendingCompare(string feature): _feature(feature) {}

    bool operator()(Shape *a, Shape *b) {
        if(_feature == "area"){
            return a->area() > b->area();
            
        }else if(_feature == "perimeter"){
            return a->perimeter() > b->perimeter();
        }
        return 0;
      }
  private:
    string _feature;
};

#endif