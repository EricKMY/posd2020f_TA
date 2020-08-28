<<<<<<< HEAD
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
=======
# **Pattern Oriented Software Design 2020 Fall Assignment 3**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===FIXME**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* * **For any output of double, it should be in the form of `%.3f`**  

## **Score** <==FIXME
1. Usage of Iterator in vector: 10%.
2. Unit tests written by yourself: 40%.
3. Unit tests written by TA: 50%.

## **Useful Reference**
[C++ Regular Expressions](http://www.cplusplus.com/reference/regex/)

## **Requirement**  
1. For this assigment, you will be sotring an input file and produce an output file, handle of the file through a new class called `Terminal`, and please used the sort funtion from class `Sort` to finish the sorting. The following are different output result by executing different command base on the same input file.
   [input.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/input.txt)<==FIXME urlchange  
   command: ```bin/sort input.txt shape_ouput.txt perimeter des info```  
   result: [info_ouput.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/info_output.txt)   
   command: ```bin/sort input.txt area_ouput.txt perimeter des area```  
   result: [area_ouput.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/area_output.txt)   
   command: ```bin/sort input.txt permiter_ouput.txt perimeter des perimeter```  
   result: [permiter_ouput.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/perimeter_output.txt)   

2. Implement a `main` function in `main.cpp` to handle input from terminal.  
   The input will be as following example:  
   ```bin/sort input.txt output.txt perimeter des area```  
   `argv[0]`: The path of binary file.  
   `argv[1]`: The full name of input file.  
   `argv[2]`: The full name of output file.  
   `argv[3]`: The attribute of shape that sorting basis on.  
   `argv[4]`: The 'des' for descending, 'asc' for asceding.  
   `argv[5]`: The output format, which is "info", "area", "perimeter" as the example txt file shown.  

3. Implement class `Terminal` in `terminal.h`.  
```
class Terminal {
public:
    Terminal(std::string input) {}
    std::string showResult() {}
}
```
* The form of the input string should be `{Shape}`+`{feature to sort}`+`{Order}`+`{feature to show}`, if any of condition missing, the constructure should handle the exception by throwing std::string "invalid input".  
  Valid: ```Rectangle (3.7, 4.2)\nEllipse (3, 4) perimeter des info```  
  Invalid: ```Rectangle (3.7, 4.2)\nEllipse (3, 4) perimeter des```   


4. Implement unit test in `ut_terminal.h` to test class`Terminal`.  
   The following is the example of unit test of Terminal.  
```
    Terminal* test1 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,-3], [-3,0], [0,-4]) perimeter des info");
    ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)\nTriangle ([0,-3], [-3,0], [0,-4])", test1->showResult());
    
    Terminal* test2 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,-3], [-3,0], [0,-4]) perimeter des perimeter");
    ASSERT_EQ("24.389\n15.800\n12.000", test2->showResult());
    
    Terminal* test3= new Terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) Triangle ([0,-3], [-3,0], [0,-4]) perimeter des area");
    ASSERT_EQ("48.820\n15.540\n6.000", test3->showResult());
```

5. Rules for the input string:  
* `{Shape}` will be in the form of `{Shape Type}` + `{SPACE}` + `{Argument}`.  
  The first letter of `{Shape Type}` should be capital.
  There must be at least one `{SPACE}` between `{Shape Type}` and `{Argument}`.  
  The `{Argument}` must be wrapped by `()` and the number must be split by `,`, but the `{SPACE}` can be ignore.  
  Valid:  
  ```
  Ellipse (3, 4)
  Ellipse     (3, 4)
  Ellipse (3,4)
  Ellipse (  3,4  )
  ```
  Invalid:  
  ```
  Ellipse(3, 4) 
  ellipse (3, 4)
  Elllllllipse (3, 4)
  Ellipse(3!4)
  Ellipse(3,@4)
  Ellipse(3, 4_)
  Ellipse @#(3, 4)
  Ellipse(3, 4, 5)
  ```
* `{Shape}` connect each other with `\n` or `{SPACE}` and no any other character between.  
  Valid:  
  ```
  Rectangle (3.7, 4.2)\nEllipse (3, 4)
  Rectangle (3.7, 4.2) Ellipse (3, 4)
  Rectangle (3.7, 4.2)  \n  Ellipse (3, 4)
  ```
  Invalid:  
  ```
  Rectangle (3.7, 4.2) \n!@#$%Ellipse (3, 4) 
  ```
* If `{Shape}` is invalid, ignore the invalide `{Shape}` and sort the remaining.  
  Example:  
  ```
  Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nEllipse$%^&(30, 40) perimeter des info");
  ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)", test->showResult());
  ```
* If the connection between `{Shape}` is invalid, ignore the `{Shape}` with invalid connection and sort the remaining.  
  Example:  
  ```
  Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nEllipse (30, 40)@#$%\nRectangle (3, 4) perimeter des info");
  ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)", test->showResult());
  ```

* `{feature to sort}` `{Order}` `{feature to show}` should all be lower case and be split by at least one space `{SPACE}` with each other, no other character should be between. If invalid throw exception std::string "invald input".  
* `{feature to sort}` and `{feature to show}` should be `info` `perimeter` `area`, other than these three will be invalidn and throw exception std::string "invald input".  
* `{order}` should be `des` or `asc`, other than these two will be invalidn and throw exception std::string "invald input".  

5. Rules for the output string:  
* each feature should connect with `\n`, no `{SPACE}` or other character should be between.  
  Valid:  
  ```
  Ellipse (3, 4)\nRectangle (3.7, 4.2)
  24.389\n15.800
  ```
  Invalid:  
  ```
  Ellipse (3, 4)  \n  Rectangle (3.7, 4.2)
  24.389  \n  15.800
  25.24.389\n15.800\n
  25.24.389\n$^15.800\n
  ```

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
      
      terminal.h

    - test

      ut_shape.cpp
      
      ut_ellipse.h

      ut_rectangle.h
      
      ut_triangle.h
      
      ut_two_dimensional_vector.h
      
      ut_sort.h
      
      ut_terminal.h

    - bin

      ut_all
      
      sort

    - makefile
    
    - input.txt

    - output.txt
>>>>>>> HW3
