# Pattern Oriented Software Design
#### Fall, 2020
#### Dept. of Computer Science and Information Engineering
#### Taipei Tech

#### Homework 3

# Purpose of the homework:
  Practice composite pattern.

  You can reference Professor's website xxx to implement following methods
  
  (You can modify method or add new method by yourself)
  
  Don't use `global function or global variable`!
  
  
  1. `addChild()` 
  
  2. `getChild()` 
  
  3. `findShape()` 

  4. `listShape()` 

# Requirements:
 1. You can reference Professor's website https://ssl-gitlab.csie.ntut.edu.tw/yccheng/posd2019f
 
 2. Implement ComplexShape class.
    
        ComplexShape(vector<Shape*> shapes,string id):Shape(id);

        double area() const 
        { 
            // Implementation area
            // return sum of all shapes area
            // For example: 
            // complexshape->area() return 3.5;
            // complexshape contains childshape
            // ├──triangle  id=1 // (0,1) (1,1) (1,2) area=0.5
            // ├──rectangle id=2 // (0,0) (0,1) (1,1) (1,0) area=1
            // └──complexshape2 id=3 contains childshape area=2
            //    ├──rectangle id=4 // (1,0) (1,1) (2,1) (2,0) area=1
            //    └──rectangle id=5 // (1,1) (1,2) (2,2) (2,1) area=1
        }

        double perimeter() const 
        { 
            // Implementation perimeter
            // return sum of all shapes perimeter
            // complexshape->perimeter() return 15.4142...;
            // complexshape contains childshape
            // ├──triangle  id=1 // (0,1) (1,1) (1,2) perimeter=3.4142...
            // ├──rectangle id=2 // (0,0) (0,1) (1,1) (1,0) perimeter=4
            // └──complexshape2 id=3 contains childshape perimeter=8
            //    ├──rectangle id=4 // (1,0) (1,1) (2,1) (2,0) perimeter=4
            //    └──rectangle id=5 // (1,1) (1,2) (2,2) (2,1) perimeter=4
        }
    
        string type() const {
            // Implementation type
            // return "complex shape"
        }


 
 3. Implement `addChild()` and `getChild()` and `findShape()` and `listShape()` method for Shape, Rectangle, Triangle, ComplexShape class.

        void addChild(Shape *shape)
        {
              // Implementation addChild
              // If shape isn't complexShape, it can't addChild
              // It should throw "Only complex shape can add!"
        }
        
        Shape *getChild(int index)
        {
              // Implementation getChild
              // If shape isn't complexShape, it can't getChild
              // It should throw "Only complex shape can get!"
        }
        
        Shape *findShape(std::string id)
        {
              // Implementation findNode
              // It should find shape where id is equal
              // If shape isn't complexShape, it can't findShape
              // It should throw "Only complex shape can find!"

        }
        
        std::string listShape()
        {
              // Implementation list child shape and sort by area
              // Result should be separated by space
              // For example: 
              // complexshape->listShape();
              // complexshape contains childshape
              // ├──triangle  id=1 // (0,1) (1,1) (1,2) area=0.5
              // ├──rectangle id=2 // (0,0) (0,1) (1,1) (1,0) area=1
              // └──complexshape2 id=3 contains childshape area=2
              //    ├──rectangle id=4 // (1,0) (1,1) (2,1) (2,0) area=1
              //    └──rectangle id=5 // (1,1) (1,2) (2,2) (2,1) area=1
              // It should return "complexshape(3) rectangle(2) triangle(1)"
              // If shape isn't complexShape, it can't listShape
              // It should throw "Not a complex shape!"
        }

     


#### File structure:
`ut_main.cpp` should include "ut_node.h"

```
├── bin
│   └── ut_all
├── src
│   ├── complex_shape.h
│   ├── rectangle.h
│   ├── shape.h
│   ├── triangle.h
│   └── two_dimensional_vector.h
├── test
│   ├── ut_complex_shape.h
│   ├── ut_main.cpp
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   └── ut_two_dimensional_vector.h
└── makefile

```

# Grading rubrics

TA assigned  test cases in CI.

# Deadline
11:59 p.m. 17 oct 2020

# Note
Make sure your all tests pass on your local machine. Then you can push to Gitlab and see the report on Jenkins.