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
   Write correspond unit test for the class in file `ut_rectangle.h` under `test` folder.  
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
    
    double perimeter() const {
        // return the perimeter of the Rectangle.
    }
    
    std::string info() const {
        // return the info of the Rectangle.
        // ex. Rectangle (3.712, 4.000)
    }
}
```

3. Implement `Ellipse` and functions inherit from `Shape`.  
   Write correspond unit test for the class in file `ut_ellipse.h` under `test` folder.  
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
    
    double perimeter() const {
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
   Write correspond unit test for the class in file `ut_triangle.h` under `test` folder.  
```
class Triangle: public Shape{
public: 
    Triangle(std::vector<TwoDimensionalCoordinate*> vectors) {
        // If the triangle can't be successfully created,
        // handle the exception by throwing string "This is not a triangle!"
    }
    
    double area() const {
        // return the area of the Triangle.
    }
    
    double perimeter() const {
        // return the perimeter of the Triangle.
    }
    
    std::string info() const {
        // return the info of the Triangle.
        // ex. Triangle ([0.000, 0.000], [0.000, -3.141], [-4.000, 0.000])
    }
}
```
4. Implement `TwoDimensionalCoordinate`.  
```
class TwoDimensionalCoordinate {
public:
    TwoDimensionalCoordinate(double x, double y):{}

    double getX() {
        // return x;
	}

	double getY() {
		// return y;
	}
};
```

5. Write correspond makefile to generate binary file for all ut file named `ut_all` under the `bin` folder.  

## **File Structure**
This time your directory structure should be like:
 - 學號_HW
    - src

      shape.h

      ellipse.h

      rectangle.h
      
      triangle.h
      
      two_dimensional_coordinate.h

    - test

      ut_shape.cpp
      
      ut_ellipse.h

      ut_rectangle.h
      
      ut_triangle.h
      
    - bin

      ut_all

    - makefile