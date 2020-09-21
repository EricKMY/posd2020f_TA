#ifndef SORT_H
#define SORT_H

#include <string>
#include <algorithm>
#include <vector> 
#include <functional>
#include "./shape.h"

using namespace std;

class Sort{
public:
    Sort(vector<Shape*>* v): _v(v){}

    template <class Compare>
    void standardSort(Compare comp) {
        sort(_v->begin(), _v->end(), comp);
    }

    template <typename Compare>
    void quickSort(Compare comp) {
        quick_sort(_v->begin(), (_v->end())-1, comp);
    }

private:
    vector<Shape*>* _v;

    template <typename Compare>
    void quick_sort(vector<Shape*>::iterator first, vector<Shape*>::iterator last, Compare comp) {
    if(first < last) {
        vector<Shape*>::iterator pivot = partition(first, last, comp);
        quick_sort(first, pivot, comp);
        quick_sort(pivot+1, last, comp);
    }
    }

    template <typename Compare>
    vector<Shape*>::iterator partition(vector<Shape*>::iterator first, vector<Shape*>::iterator last, Compare comp) {
        vector<Shape*>::iterator pivot = first + (last - first) / 2;
        vector<Shape*>::iterator i = first - 1;
        vector<Shape*>::iterator j = last + 1;
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
};

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