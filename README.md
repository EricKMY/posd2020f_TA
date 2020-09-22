# **Pattern Oriented Software Design 2020 Fall Assignment 2**  

## **Notice**  
* **Due on (Monday, September 29, 2020 23:59).**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For retrun string of number, should be in form of `%3f`.**  

## **Score**

1. Unit tests written by yourself: 30%.  
2. Unit tests written by TA: 50%.  
3. Implementaion of `quickSort()`: 10%.  
4. Use `iterator` to access element of vector: 10%.  

## **Useful Reference**
[C++ Vector](http://www.cplusplus.com/reference/vector/vector/)  
[C++ Sort](http://www.cplusplus.com/reference/algorithm/sort/)  
[C++ Function Templates](http://www.cplusplus.com/doc/oldtutorial/templates/)  
[QuickSort](https://en.wikipedia.org/wiki/Quicksort)  

## **Requirement**  
1. Modify exception handle of class `Ellipse`.  
*  Change the exception string into "This is not an ellipse!"  
*  Make sure semiMajorAxes >= semiMinorAxes, if not throw exception "This is not an ellipse!"  

2. Implement class `Sort` in `sort.h`.  
```
class Sort{
public:
    Sort(std::vector<Shape*>* shapes) {}
    void standardSort(Compare comp) {}
    void quickSort(Compare comp) {}
};
```
* `Compare`: Is a template parameter, should be able to accept `lambda`, `function`, and `object`.  
* `standardSort()`: Implement function by using std::sort.  
* `quickSort()`: Implement a quicksort function WITHOUT using any sorting function from c/c++ library, you should write the sorting algorithm by youself.  

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
    Sort sort(&shapes);
    sort.standardSort(areaAscendingCompare);
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
* The following is the example usage of compare object.  
```
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Ellipse(4, 3));
    Sort sort(&shapes);
    sort.standardSort(AscendingCompare("area"));
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