# **Pattern Oriented Software Design 2020 Fall Assignment 5**  

## **Notice**  
* **Due on Tuesday October 27 2020, 23:59.**  
* **If your code fails to compile on jenkins server, you'll get no point for the assignment.**  
* **You should add unit test for each requirment under corresponding ut_file.**  
* **DO NOT use any Type Checking or Dynamic Type that would violet OCP to implement Composite pattern and Iterator pattern, -40 point if you do so.**  

## **Score**  
1. Source Code(Implementation + unit test): 40%.  
2. Unit tests written by TA: 60%.  

## **Useful Reference**  
[Composite Pattern](https://refactoring.guru/design-patterns/composite)  
[Iterator Pattern](https://refactoring.guru/design-patterns/iterator)  
[Open–closed principle](http://joelabrahamsson.com/a-simple-example-of-the-openclosed-principle/)  
[std::deque](http://www.cplusplus.com/reference/deque/deque/)  
[std::list](http://www.cplusplus.com/reference/list/list/)  
[Deque vs Vector](https://www.geeksforgeeks.org/deque-vs-vector-in-c-stl/)  
[List vs Vector](https://www.geeksforgeeks.org/difference-between-vector-and-list/)  

## **Requirement**  
1. Add the following function in `Shape`, `shape.h` should remain as pure interface, add the implementations in `shape.cpp`.  
```
class Shape {
    virtual std::string type() const = 0;
    virtual Iterator* createIterator() const; // return NullIterator
}
```
* `type()`: type of shape is "Ellipse", "Rectangle", "Triangle", "Compound Shape".  

2. Add the following function in `CompoundShape`, and modify the constructor as follow.  
```
class CompoundShape {
    CompoundShape(std::string id, std::list<Shape*>* shapes) {}
    Iterator* createIterator() const; // return ShapeIterator
}
```

2. Implement `Iterator` class interface in `iterator.h`.  
```
class Iterator {
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual Shape* currentItem() = 0;
};
```

3. Implement `NullIterator` class in `null_iterator.h` and the corresponding unit test in `ut_iterator.h`.  
```
class NullIterator : public Iterator {
public:
    void first() {
        // throw std::string "No child member!"
    }

    void next() {
        // throw std::string "No child member!"
    }
    
    bool isDone(){
      // return true
    }
    
    Shape* currentItem(){
        // throw std::string "No child member!"
    }
};
```

5. Implement `ShapeIterator` class in `shape_iterator.h` and the corresponding unit test in `ut_iterator.h`.  
```
class ShapeIterator : public Iterator {
public:
    ShapeIterator(RandomAccessIterator begin, RandomAccessIterator end) {
        // initialize iterator.
    }
    
    void first() {
        // initialize iterator.
    }
    
    void next() {
        // move iterator to next position,
        // throw std::string "Moving past the end!" when iterator move over the range of the structure.
    }
    
    bool isDone(){
      // return true when iterator reach the end of the structure.
    }
    
    Shape* currentItem(){
        // return the shape iterator currently point to.
    }
};
```

6. Implement following function in `utility.h` and the corresponding unit test in `ut_utility.h`.  
```
Shape* getShapeById(Shape* shape, std::string id) {}

template <class Filter>
std::deque<Shape*> filterShape(Shape *shape, Filter filter) {}
```
* `getShapeById()`: Return a shape under the input shape tree sturctur that matches the id.  
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
* `getShapeById()`: Should throw std::string "Expected get shape but shape not found" when no shape found with the given id.   

* `filterShape()`: Return the shapes under the input shape tree sturctur that match the given filter.  
* `filterShape()`: Should throw std::string "Only compound shape can filter shape!" when the input shape is not iterable.  

7. Implement following class in `utility.h` and the corresponding unit test in `ut_utility.h`.  
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