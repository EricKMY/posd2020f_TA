# **Pattern Oriented Software Design 2020 Fall Assignment 1**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===fixme**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  

## **Score**
1. Unit tests written by yourself: 50%.
2. Unit tests written by TA: 50%.

## **Useful Reference**
[Makefile](https://en.wikipedia.org/wiki/Makefile)

## **Requirement**  
1. Implement class `Shape`, `Ellipse`, `Rectangle`, `Triangle`, `Two Dimensional Vector`.  
**Note: Each class below are the skeleton. You should finish implementation by yourself.**  

```
class Shape{
public:
    virtual double area() const = 0; // reutrn area of shape.
    virtual double perimeter() const = 0; // return perimeter of shape.
    virtual string type() const = 0; // return type of shape, "rectangle" "ellipse" "triangle".
};
```

```
class Rectangle: public Shape{
public: 
    Rectangle(double length, double width): _length(length), _width(width){
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
    }
}
```

```
class Ellipse: public Shape{
public: 
    Ellipse(double semiMajorAxes, double semiMinorAxes): _semiMajorAxes(semiMajorAxes), _semiMinorAxes(semiMinorAxes){
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
    }
}
```

```
class Triangle: public Shape{
public: 
    Triangle(vector<TwoDimensionalVector*> vectors): _vectors(vectors){
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }
}
```

```
class TwoDimensionalVector{
public:
	TwoDimensionalVector(int x, int y): _x(x), _y(y) {}
	int getX() { // return value of x. }
	int getY() { // return value of y. }
	double length() { // reuturn length of the vector. }
	int dot(TwoDimensionalVector* vector) { // reuturn dot with the input vector => self · input }
	int cross(TwoDimensionalVector* vector) { // reuturn cross with the input vector => self X input }
	TwoDimensionalVector* subtract(TwoDimensionalVector* vector) { // reuturn subtract with the input vector => self - input }
};
```

* Implement `area()`, `perimeter()`, `type()` in each children class of Shape.
* Use `M_PI` in <math.h> for caculation of `π`.

2. Implement unit test for each concrete class with separate unit test file, which means we need `ut_ellipse.h`, `ut_rectangle.h`, `ut_triangle.h`, `ut_two_dimentional_vector.h` and put them all under the `test` folder.
3. Write the corresponding makefile to generate executable file which named `ut_all` under the `bin` folder. 

## **File Structure**
This time your directory structure should be like:
 - 學號_HW
    - src

      shape.h

      ellipse.h

      rectangle.h
      
      triangle.h
      
      two_dimensional_vector.h

    - test

      ut_shape.cpp
      
      ut_ellipse.h

      ut_rectangle.h
      
      ut_triangle.h
      
      ut_two_dimensional_vector.h

    - bin

      ut_all

    - makefile