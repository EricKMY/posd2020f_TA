#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "two_dimensional_vector.h"
#include <math.h>
#include <vector>
#include <string>

using namespace std;

class Triangle : public Shape{
    public: 
		Triangle(vector<TwoDimensionalVector*> vectors):_vectors(vectors){
      if(vectors.size() != 3) {
        throw string("this is not a triangle!");
      }else if(area() == 0) {
        throw string("this is not a triangle!");
      }
    }

    // Triangle(vector<int> t){}
    
    
    double area() const {
      return fabs(
              _vectors[0]->getX() * _vectors[1]->getY()
               + _vectors[1]->getX() * _vectors[2]->getY() 
               + _vectors[2]->getX() * _vectors[0]->getY() 
               - _vectors[0]->getX() * _vectors[2]->getY() 
               - _vectors[1]->getX() * _vectors[0]->getY() 
               - _vectors[2]->getX() * _vectors[1]->getY()) / 2;
    }

    double perimeter() const {
      return sqrt(pow(_vectors[0]->getX() - _vectors[1]->getX(), 2) + pow(_vectors[0]->getY() - _vectors[1]->getY(), 2))
           + sqrt(pow(_vectors[0]->getX() - _vectors[2]->getX(), 2) + pow(_vectors[0]->getY() - _vectors[2]->getY(), 2)) 
           + sqrt(pow(_vectors[2]->getX() - _vectors[1]->getX(), 2) + pow(_vectors[2]->getY() - _vectors[1]->getY(), 2));
    }

    string info() const {
      char result[100];
      sprintf(result, "Triangle ([%.3f,%.3f], [%.3f,%.3f], [%.3f,%.3f])"
      , _vectors[0]->getX(), _vectors[0]->getY()
      , _vectors[1]->getX(), _vectors[1]->getY()
      , _vectors[2]->getX(), _vectors[2]->getY());
      
      return result;
    }


    private:
    vector<TwoDimensionalVector*> _vectors;
};

#endif
