# HW3

# **Pattern Oriented Software Design 2020 Fall Assignment 3**  

## **Notice**  
* **Due on (Monday, June 22, 2020 23:59). <===FIXME**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  

## **Score** <==FIXME
1. Usage of Iterator in vector: 10%.
2. Unit tests written by yourself: 40%.
3. Unit tests written by TA: 50%.

## **Useful Reference**
[C++ Regular Expressions](http://www.cplusplus.com/reference/regex/)

## **Requirement**  
1. For this assigment, you will be sotring an input file and produce an output file, handle of the file through a new class called `Terminal`, and please used the sort funtion from class `Sort` to finish the sorting. The following are different output result by executing different command base on the same input file.
   [input.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/input.txt)<==FIXME urlchange  
   command: ```bin/sort input.txt info_output.txt perimeter dec info```  
   result: [info_output.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/info_output.txt)   
   command: ```bin/sort input.txt area_output.txt perimeter dec area```  
   result: [area_output.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/area_output.txt)   
   command: ```bin/sort input.txt perimeter_output.txt perimeter dec perimeter```  
   result: [perimeter_output.txt](https://ssl-gitlab.csie.ntut.edu.tw/108598011/posd2020f_ta/blob/HW3/perimeter_output.txt)   

2. Implement a `main` function in `main.cpp` to handle input from terminal.  
   The input will be as following example:  
   ```bin/sort input.txt output.txt perimeter dec area```  
   `argv[0]`: The path of binary file.  
   `argv[1]`: The full name of input file.  
   `argv[2]`: The full name of output file.  
   `argv[3]`: The attribute of shape that sorting basis on.  
   `argv[4]`: The 'dec' for decending, 'asc' for asceding.  
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
  Valid: ```Rectangle (3.7, 4.2)\nEllipse (3, 4) perimeter dec info```  
  Invalid: ```Rectangle (3.7, 4.2)\nEllipse (3, 4) perimeter dec```   


4. Implement unit test in `ut_terminal.h` to test class`Terminal`.  
   The following is the example of unit test of Terminal.  
```
    Terminal* test1 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,-3], [-3,0], [0,-4]) perimeter dec info");
    ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)\nTriangle ([0,-3], [-3,0], [0,-4])", test1->showResult());
    
    Terminal* test2 = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nTriangle ([0,-3], [-3,0], [0,-4]) perimeter dec perimeter");
    ASSERT_EQ("24.389\n15.800\n12.000", test2->showResult());
    
    Terminal* test3= new Terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) Triangle ([0,-3], [-3,0], [0,-4]) perimeter dec area");
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
* `{Shape}` connect each other with `\n` and no `{SPACE}` or any other character between.  
  Valid:  
  ```
  Ellipse (3, 4) 
  Rectangle (3.7, 4.2)\nEllipse (3, 4) 
  ```
  Invalid:  
  ```
  Rectangle (3.7, 4.2)\nEllipse (3, 4)\n
  Rectangle (3.7, 4.2)  \n  Ellipse (3, 4)
  Rectangle (3.7, 4.2)\n!@#$%Ellipse (3, 4) 
  ```
* If `{Shape}` is invalid, ignore the invalide `{Shape}` and sort the remaining.  
  Example:  
  ```
  Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nEllipse$%^&(30, 40) perimeter dec info");
  ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)", test->showResult());
  ```
* If the connection between `{Shape}` is invalid, ignore the `{Shape}` with invalid connection and sort the remaining.  
  Example:  
  ```
  Terminal* test = new Terminal("Rectangle (3.7, 4.2)\nEllipse (3, 4)\nEllipse (30, 40)@#$%\nRectangle (3, 4) perimeter dec info");
  ASSERT_EQ("Ellipse (3, 4)\nRectangle (3.7, 4.2)", test->showResult());
  ```

* `{feature to sort}` `{Order}` `{feature to show}` should all be lower case and be split by at least one space `{SPACE}` with each other, no other character should be between. If invalid throw exception std::string "invald input".  
* `{feature to sort}` and `{feature to show}` should be `info` `perimeter` `area`, other than these three will be invalidn and throw exception std::string "invald input".  
* `{order}` should be `dec` or `asc`, other than these two will be invalidn and throw exception std::string "invald input".  

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
* For the feature `perimeter` and `area`, the number should be in the form of `%.3f`.
  Valid:  
  ```
  12.000
  24.389
  ```
  Invalid:  
  ```
  12
  24.389456
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