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
    void standardSort(Compare comp) {}
    void customizeSort(Compare comp) {}
};

bool areaAscendingCompare(Shape *a, Shape *b) {};

bool areaDescendingCompare(Shape *a, Shape *b) {};

bool perimeterAscendingCompare(Shape *a, Shape *b) {};

bool perimeterDescendingCompare(Shape *a, Shape *b) {};

class AscendingCompare{
  public:
    AscendingCompare(String attribute): _attribute(attribute) {}
};

class DecendingCompare{
  public:
    DecendingCompare(String attribute): _attribute(attribute) {}
};

#endif