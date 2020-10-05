# **Pattern Oriented Software Design 2020 Fall Assignment 4**  

## **Notice**  
* **Due on Tuesday October 13 2020, 23:59.  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each newly add requirment under corresponding ut_file.**  

## **Score** <==FIXME
1. Usage of Iterator in vector: 10%.  
2. Unit tests written by yourself: 40%.  
3. Unit tests written by TA: 50%.  

## **Useful Reference**  
[Composite pattern](https://en.wikipedia.org/wiki/Composite_pattern)  
[Iterators in C++](geeksforgeeks.org/iterators-c-stl/)  
[C++ Overloading](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm)  

## **Requirement**   

1. Add the following virtual function in `Shape`, add the implementations in `shape.cpp` if needed.   
 ```
class Shape {
public:
    Shape(std::string id) // interface for default color "white".
    Shape(std::string id, std::string color); // interface for color input by user.
    string id() const; // return id of shape
    string color() const; // return color of shape.
    virtual void addShape(Shape *shape); // throw std::string "Only complex shape can add shape!"
    virtual void deleteShapeById(std::string id); // throw std::string "Only complex shape can delete shape!"
    virtual Shape* getShapeById(std::string id); // throw std::string "Only complex shape can get shape!"
};
```
*  `id` should be globally unique.
*  `color`: is input as "red", "blue", "yellow" etc.

2. Modify interface of `Ellipse`, `Rectangle`, `Triangle` into the following interface.  
   (Now you will have two interface for each of these three shapes.)

```
Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes) 
Ellipse(std::string id, double semiMajorAxes, double semiMinorAxes, std::string color)

Rectangle(std::string id, double length, double width)
Rectangle(std::string id, double length, double width, std::string color)

Triangle(std::string id, vector<TwoDimensionalCoordinate*> vectors)
Triangle(std::string id, vector<TwoDimensionalCoordinate*> vectors, std::color)
```

3. Implement `CompoundShape` class in `compound_shape.h` and the corresponding unit test in `ut_compound_shape.h`.  
```
class CompoundShape : public Shape {
public:
        CompoundShape(string id, vector<Shape*>* shapes) {
            // The default color of compound shape should be "Transparent".
            
            // When there's no shape contain in the compound shape,
            // should throw std::string "This is not a compound shape!"
        }

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
            // add shape into compound shape.
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
```
├── bin
│   └── ut_all
├── src
│   ├── shape.h
│   ├── shape.cpp
│   ├── ellipse.h
│   ├── rectangle.h
│   ├── triangle.h
│   ├── compound_shape.h
│   └── two_dimensional_vector.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_compound_shape.h
│   └── ut_two_dimensional_vector.h
└── makefile

```