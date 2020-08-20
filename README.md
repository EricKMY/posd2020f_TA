# **Pattern Oriented Software Design 2020 Fall Assignment 2**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===fixme**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  

## **Score**
1. Usage of Iterator in vector: 10%.
2. Unit tests written by yourself: 40%.
3. Unit tests written by TA: 50%.

## **Useful Reference**
[std::vector](http://www.cplusplus.com/reference/vector/vector/)  
[std::sort](http://www.cplusplus.com/reference/algorithm/sort/)  
[Templates](http://www.cplusplus.com/doc/oldtutorial/templates/)  
[QuickSort](https://en.wikipedia.org/wiki/Quicksort)  

## **Requirement**  
1. Implement class `Sort` in `sort.h`.  
```
class Sort{
public:
    Sort(std::vector<Shape*>* v) {}
    void standardSort(Compare comp) {}
    void customizeSort(Compare comp) {}
};
```
* `Compare`: Is a template parameter, should be able to accept `lambda`, `function`, and `object`.  
* `standardSort()`: Implement function by using std::sort.  
* `customizeSort()`: Implement a quicksort function WITHOUT using any sorting function from c/c++ library,  
   you should write the sorting algorithm by youself. Also use `Iterator` of vector to control vector.   

2. Implement the following function in `sort.h`.  

```
bool areaAscendingCompare(Shape *a, Shape *b) {};

bool areaDescendingCompare(Shape *a, Shape *b) {};

bool perimeterAscendingCompare(Shape *a, Shape *b) {};

bool perimeterDescendingCompare(Shape *a, Shape *b) {};

```
* These function should be argument of `standardSort()` and `customizeSort()`.  
  ex. standardSort(areaAscendingCompare).   


3. Implement class `AscendingCompare` and `DescendingCompare` in `sort.h`.
```
class AscendingCompare{
  public:
    AscendingCompare(std::string feature): _feature(feature) {}
};

class DescendingCompare{
  public:
    DescendingCompare(std::string feature): _feature(feature) {}
};
```
* `feature`: is the feature of shape you wanted to compare, meaning "area" and "perimeter".  
* These object should be argument of `standardSort()` and `customizeSort()`.  
  ex. AscendingCompare ascendingCompare = new AscendingCompare("area");  
  standardSort(ascendingCompare);  

## **File Structure**
This time your directory structure should be like:
 - 學號_HW
    - src

      shape.h

      ellipse.h

      rectangle.h
      
      triangle.h
            
      two_dimensional_vector.h
      
      sort.h

    - test

      ut_shape.cpp
      
      ut_ellipse.h

      ut_rectangle.h
      
      ut_triangle.h
      
      ut_two_dimensional_vector.h
      
      ut_sort.h

    - bin

      ut_all

    - makefile