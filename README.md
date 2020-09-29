# **Pattern Oriented Software Design 2020 Fall Assignment 4**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===FIXME**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **For any output of double, it should be in the form of `%.3f`**  

## **Score** <==FIXME
1. Usage of Iterator in vector: 10%.  
2. Unit tests written by yourself: 40%.  
3. Unit tests written by TA: 50%.  

## **Useful Reference**  
[Composite pattern](https://en.wikipedia.org/wiki/Composite_pattern)  

## **Requirement**   

1. Add the following virtual function in `Shape`, add the implementations in `shape.cpp` if needed.   
 ```
class Shape {
public:
    Shape(string id); // id should be globally unique
    virtual void addShape(Shape *shape); // throw std::string "Only Compound shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only Compound shape can delete shape!"
    virtual Shape* getShapeById(std::string id); // throw std::string "Only Compound shape can get shape!"
};
```
2. Modify interface of `Ellipse`, `Rectangle`, `Triangle` into the following.  

```
Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) 
Rectangle(std::string id, double length, double width)
Triangle(std::string id, vector<TwoDimensionalCoordinate*> vectors)
```

3. Implement `CompoundShape` class in `compoundShape.h` and the corresponding unit test in `ut_complex_shape.h`.  
```
CompoundShape(string id, vector<Shape*>* shapes) {

        double area() const {
            // return sum of all containing shapes area.
        }

        double perimeter() const { 
            // return sum of all containing shapes perimeter.
        }
    
        string info() const {
            // return list of all containing shapes info with wrapped of "CompoundShape {}".
            // ex."CompoundShape {[Rectangle (3.7, 4.2), Ellipse (3, 4), Triangle ([0,-3], [-3,0], [0,-4])]}"
        }
        
        void addShape(Shape* shape) {
            // add shape into Compound shape.
        }
        
        void deleteShapeById(string id) {
            // search and delete a shape through id,
            // search all the containing shapes and the tree structure bellow,
            // if no match of id, throw std::string "Expected delete shape but shape not found"
        }
        
        Shape* getShapeById(string id) {
            // search and return a shape through id,
            // search all the containing shapes and the tree structure bellow,
            // if no match of id, throw std::string "Expected get shape but shape not found"
        }
}
```
     


#### File structure:
`ut_main.cpp` should include "ut_complex_shape.h"

```
├── bin
│   └── ut_all
├── src
│   ├── shape.h
│   ├── shape.cpp
│   ├── ellipse.h
│   ├── rectangle.h
│   ├── triangle.h
│   └── two_dimensional_vector.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_complex_shape.h
│   └── ut_two_dimensional_vector.h
└── makefile

```