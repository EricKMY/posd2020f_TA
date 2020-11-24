# **Pattern Oriented Software Design 2020 Fall Assignment 7**  

## **Notice**  
* **Due on Tuesday December 1 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  

## **Score**  
1. `Scanner` (source code + TA test): 20%.  
2. `ShapeBuilder` (source code + TA test): 50%.  
3. `ShapeParser` (source code + TA test): 30.  
4. -5% for each fail TA unit test.  

## **Useful Reference**  
[Builder Pattern](https://refactoring.guru/design-patterns/builder)  

## **Requirement**  
1. Modify `Compound Shape` constructor, now it's available to accpet empty std::list<Shape*> without throwing exception.  

2. Add class `Scanner` in `scanner.h` and corresponding unit test in `ut_scanner.h`.  
```
class Scanner {
public:
    Scanner(std::string input) {}
    
    std::string nextToken() {}
};
```
* Purpose of the scanner is to scan through the input and able to send out each token by nextToken().  
* Ignore the token which is illegal.  
* For input of `Ellipse` it should be in form of `Ellipse (%.3f, %.3f)`.  
* For input of `Rectangle` it should be in form of `Triangle (%.3f, %.3f)`.  
* For input of `Triangle` it should be in form of `Triangle (%.3f, %.3f, %.3f, %.3f, %.3f, %.3f)`.  
* For input of `Compound Shape` it should be in form of `CompoundShape {}`.  
* Each Shape should be separate with `,`.  

3. Add class `ShapeBuilder` in `shape_builder.h` and corresponding unit test in `ut_shape_builder.h`.  
```
class ShapeBuilder {
public:
    ShapeBuilder() {}
    
    void buildRectangle(double length, double width) {
        // build a rectangle with an unique id and push in a result stack.
    }
    
    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        // build a ellipse with an unique id and push in a result stack.
    }
    
    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        // build a triangle with an unique id and push in a result stack.
    }
    
    void buildCompoundShapeBegin() {
        // for notifing beginning of a Compound Shape.
    }
    
    void buildCompoundShapeEnd() {
        // for notifing ending of a Compound Shape.
    }
    
    std::stack<Shape*> getResult() {
        // return result stack.
    }
};
```
4. Add class `ShapeParser` in `shape_parser.h` and corresponding unit test in `ut_shape_parser.h`.  
```
class ShapeParser {
public:
    ShapeParser(std::string input) {
        // initialize a scanner for handling input.
        // initialize a shape builder for handling building shape.
    }
    
    void parser() {
        // using Scanner::nextToken() to get all information to determine what to build,
        // and provid the argument the shape needed.
        // use functions in ShapeBuilder to build out the shape.
    }
    
    std::stack<Shape*> getResult() {
        // reutrn result stack.
    }
};
```

#### File structure:  
```
├── bin
│   └── ut_main
├── src
│   ├── shape.h
│   ├── shape.cpp
│   ├── ellipse.h
│   ├── rectangle.h
│   ├── triangle.h
│   ├── compound_shape.h
│   ├── iterator.h
│   ├── null_iterator.h
│   ├── shape_iterator.h
│   ├── utility.h
│   ├── visitor.h
│   ├── area_visitor.h
│   ├── info_visitor.h
│   ├── scanner.h
│   ├── shape_builder.h
│   ├── shape_parser.h
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_compound_shape.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   ├── ut_visitor.h
│   ├── ut_scanner.h
│   ├── ut_shape_builder.h
│   └── ut_shape_parser.h
└── makefile

```