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

    template <typename Compare>
    void standardSort(Compare comp) {
        std::sort(_v->begin(), _v->end(), comp);
    }

    template <typename Compare>
    void customizeSort(Compare comp) {
      quickSortOperator(_v->begin(), _v->end() - 1, comp);
    }


    typedef std::vector<Shape *>::iterator shapeIterator;

    template <typename Compare>
    void quickSortOperator(shapeIterator left, shapeIterator right, Compare comp)
    {
        if(std::distance(left,right)>=2)
        {
            shapeIterator pivot = partition(left, right, comp);
            quickSortOperator(left, pivot - 1, comp); 
            quickSortOperator(pivot + 1, right, comp);
        }
    }

    template <typename Compare>
    shapeIterator partition(shapeIterator left, shapeIterator right, Compare comp)
    {
        shapeIterator indexItr = left-1;

        shapeIterator visitItr = left;

        while(visitItr < right)
        {
            if(comp(*visitItr, *right))
            {
                ++indexItr;
                std::swap(*indexItr, *visitItr);
            }
            ++visitItr;
        }

        std::swap(*(indexItr + 1), *right); 

        return ++indexItr;
    }

    private:
    vector<Shape*>* _v;
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



class AscendingCompare{
  public:
    AscendingCompare(string attribute): _attribute(attribute) {}

    bool operator()(Shape *a, Shape *b) {
        if(_attribute == "area"){
            return a->area() < b->area();
            
        }else if(_attribute == "perimeter"){
            return a->perimeter() < b->perimeter();

        }

        return 0;
      }

  private:
    string _attribute;
};

class DecendingCompare{
  public:
    DecendingCompare(string attribute): _attribute(attribute) {}

    bool operator()(Shape *a, Shape *b) {
        if(_attribute == "area"){
            return a->area() > b->area();
            
        }else if(_attribute == "perimeter"){
            return a->perimeter() > b->perimeter();

        }

        return 0;
      }

  private:
    string _attribute;
};

#endif