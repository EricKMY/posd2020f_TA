# **Pattern Oriented Software Design 2020 Fall Assignment 5**  

## **Notice**  
* **Due on Tuesday October 20 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  

## **Score**  
1. Usage of Iterator in vector: 10%.  
2. Unit tests written by yourself: 40%.  
3. Unit tests written by TA: 50%.  

## **Useful Reference**  
[Composite Pattern](https://en.wikipedia.org/wiki/Composite_pattern)  
[Iterator Pattern](https://en.wikipedia.org/wiki/Iterator_pattern)   

## **Requirement**  
1. Add the following function in `Shape`, add the implementations in `shape.cpp` if needed.  
```
class Shape {
    virtual string type() const = 0;
    virtual Iterator *createIterator() {}
}
```
* `type()`: type of shape is "Ellipse", "Rectangle", "Triangle", "Compound Shape".

2. Implement `Iterator` class in `iterator.h` and the corresponding unit test in `ut_iterator.h`.  
```
class Iterator {
public:
    virtual void first() = 0;
    virtual Shape* currentItem() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
};
```

3. Implement `NullIterator` class in `null_iterator.h`.  
```
class NullIterator : public Iterator {
    public:
    void first() {
        // throw std::string "No child member!"
    }

    Shape* currentItem(){
        // throw std::string "No child member!"
    }

    void next() {
        // throw std::string "No child member!"
    }
    bool isDone(){
      // return true
    }
};
```

4. Implement following function in `utility.h` and the corresponding unit test in `ut_utility.h`.  
   **DO NOT use any Type Checking to implement the following function.**
```
Shape* getShapeById(Shape* shape, string id) {}

template <class Filter>
vector<Shape*> filterShape(Shape *shape, Filter filter) {}
```
* `getShapeById()`: Return the shape under the input shape tree sturctur that matches the id.  
  Example:  
```
  getShapeById(compoundShape_0, 2);
  
  CompoundShape(id:0)
  │
  ├── CompoundShape(id:1)
  │    │
  │    └── Triangle(id:2) <=== return this
  │
  ├── Ellipse(id:3)
  │
  └── Rectangle(id:4)
```
* `getShapeById()`: Should throw std::string "Only compound shape can get shape!" when the input shape is not iterable.  
* `getShapeById()`: Should throw std::string "Expected get shape but shape not found" when no shpe found with the given id.   

* `filterShape()`: Return the shapes under the input shape tree sturctur that match the given filter.  
* `filterShape()`: Should throw std::string "Only compound shape can get shape!" when the input shape is not iterable.  

5. Implement following class in `utility.h` and the corresponding unit test in `ut_utility.h`.  
```
class AreaFilter {
    AreaFilter(double upperBound, double lowerBound) {}
};

class PerimeterFilter {
    PerimeterFilter(double upperBound, double lowerBound) {}
};

class ColorFilter {
    ColorFilter(std::string color) {}
};

class TypeFilter {
    TypeFilter(std::string type) {}
};
```
* Example usage of `filterShape()` with the filter class:  
```
filterShape(compoundShape_0, AreaFilter(10, 5);
// retrun shapes area 10 >= and 5 <=, but don't include compoundShape_0 itself.

filterShape(compoundShape_0, PerimeterFilter(10, 5);
// retrun shapes perimeter 10 >= and 5 <=, but don't include compoundShape_0 itself.

filterShape(compoundShape_0, ColorFilter("white");
// retrun shapes that match "white", but don't include compoundShape_0 itself.

filterShape(compoundShape_0, TypeFilter("Compound Shape");
// retrun shapes that match "Compound Shape", but don't include compoundShape_0 itself.
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
│   ├── iterator.h
│   ├── null_iterator.h
│   ├── utility.h
│   └── two_dimensional_coordinate.h
├── test
│   ├── ut_main.cpp
│   ├── ut_ellipse.h
│   ├── ut_rectangle.h
│   ├── ut_triangle.h
│   ├── ut_iterator.h
│   ├── ut_utility.h
│   └── ut_compound_shape.h
└── makefile

```