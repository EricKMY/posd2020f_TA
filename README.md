# HW1

# **Pattern Oriented Software Design 2020 Fall Assignment 1**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===fixme**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For any output of double, it should be in the form of `%.3f`**  

## **Score**
1. Unit tests written by yourself: 50%.  
2. Unit tests written by TA: 50%.  

## **Useful Reference**
[Makefile](https://en.wikipedia.org/wiki/Makefile)  
[Googletest Primer](https://github.com/google/googletest/blob/master/googletest/docs/primer.md)  

## **Requirement**  
**Note: Each class below are the skeleton. You should finish implementation by yourself.**  

1. `Shape` is an abstract class , don't modify it!!!  
```
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string info() const = 0;
};
```

2. Implement `Rectangle` and functions inherit from `Shape`.  
```
class Rectangle: public Shape {
public: 
    Rectangle(double length, double width) {
        // If the rectangle can't be successfully created,
        // handle the exception by throwing string "This is not a rectangle!"
    }
    
    double area() const {
        // return the area of the Rectangle.
    }
    
    double perimeter() {
        // return the perimeter of the Rectangle.
    }
    
    std::string info() const {
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
    }
}
```

3. Implement `Ellipse` and functions inherit from `Shape`.  
```
class Ellipse: public Shape{
public: 
    Ellipse(double semiMajorAxes, double semiMinorAxes) {
        // If the ellipse can't be successfully created,
        // handle the exception by throwing string "This is not a ellipse!"
    }
    
    double area() const {
        // return the area of the Ellipse.
    }
    
    double perimeter() {
        // return the perimeter of the Ellipse.
    }
    
    std::string info() const {
        // return the info of the Ellipse.
        // ex. Ellipse (3.712, 4.000)
    }
}
```
* Use `M_PI` in <math.h> for caculation of `π`.  


4. Implement `Triangle` and functions inherit from `Shape`.  
```
class Triangle: public Shape{
public: 
    Triangle(vector<TwoDimensionalVector*> vectors) {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }
    
    double area() const {
        // return the area of the Triangle.
    }
    
    double perimeter() {
        // return the perimeter of the Triangle.
    }
    
    std::string info() const {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
    }
}
```
4. Implement `TwoDimensionalVector`.  
```
class TwoDimensionalVector{
public:
	TwoDimensionalVector(double x, double y): _x(x), _y(y) {}
	double getX() { // return value of x. }
	double getY() { // return value of y. }
	double length() { // reuturn length of the vector. }
	double dot(TwoDimensionalVector* vector) { // reuturn dot with the input vector => self · input }
	double cross(TwoDimensionalVector* vector) { // reuturn cross with the input vector => self X input }
	TwoDimensionalVector* subtract(TwoDimensionalVector* vector) { // reuturn subtract with the input vector => self - input }
};
```

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