# **Pattern Oriented Software Design 2020 Fall Assignment 2**  

## **Notice**  
* **Due on (Monday, September 29, 2020 23:59).**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For retrun string of number, should be in form of `%3f`.**  

## **Score**

1. Unit tests written by yourself: 35%.  
2. Unit tests written by TA: 50%.  
3. Implementaion of `quickSort()`: 15%.  

## **Useful Reference**
[C++ Vector](http://www.cplusplus.com/reference/vector/vector/)  
[C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/)  
[C++ Function Templates](http://www.cplusplus.com/doc/oldtutorial/templates/)  
[QuickSort Wiki](https://en.wikipedia.org/wiki/Quicksort)  

## **Requirement**  
1. Modify exception handle of class `Ellipse`.  
*  Change the exception string into "This is not an ellipse!"  
*  Make sure semiMajorAxes >= semiMinorAxes, if not throw exception "This is not an ellipse!"  

2. Implement `quickSort()` in `sort.h` and write corresponding unit test in `ut_sort.h`.  
```
void quickSort(RandomAccessIterator first, RandomAccessIterator last, Compare comp) {}
```
* `Compare`:A template parameter, binary function that accepts two elements in the range as arguments, and returns a value convertible to bool. This can either be a function pointer or a function object. (You may reference [C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/))  
* `RandomAccessIterator`:A template parameter, random-access iterators to the initial and final positions of the sequence to be sorted. (You may reference [C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/))  
* `quickSort()`: Implement a quicksort function **WITHOUT using any sorting function from c/c++ library**, you should write the sorting algorithm by youself. (You may reference [QuickSort Wiki](https://en.wikipedia.org/wiki/Quicksort))  

3. Implement the following public function in `sort.h`.  

```
bool areaAscendingCompare(Shape *a, Shape *b) {};

bool areaDescendingCompare(Shape *a, Shape *b) {};

bool perimeterAscendingCompare(Shape *a, Shape *b) {};

bool perimeterDescendingCompare(Shape *a, Shape *b) {};

```
* The following is the example usage of compare funtion.  
```
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Ellipse(4, 3));
    quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);

    ASSERT_EQ(12, shapes[0]->area());
    ASSERT_NEAR(37.699, shapes[1]->area(), 0.001);
```


4. Implement class `AscendingCompare` and `DescendingCompare` in `sort.h`.
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
* The following is the example usage of compare obj.  
```
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Ellipse(4, 3));
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));

    ASSERT_EQ(12, shapes[0]->area());
    ASSERT_NEAR(37.699, shapes[1]->area(), 0.001);
```

## **File Structure**
This time your directory structure should be like:
```
{學號}_hw
    ├── bin
    │   └── ut_main
    ├── src
    │   ├── shape.h
    │   ├── ellipse.h
    │   ├── rectangle.h
    │   ├── triangle.h
    │   ├── sort.h
    │   └── two_dimensional_coordinate.h
    ├── test
    │   ├── ut_main.cpp
    │   ├── ut_ellipse.h
    │   ├── ut_rectangle.h
    │   ├── ut_sort.h
    │   └── ut_triangle.h
    └── makefile
```