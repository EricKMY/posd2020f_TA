// #ifndef COMPLEX_SHAPE_H
// #define COMPLEX_SHAPE_H

// #include <string>
// #include <vector>
// #include "shape.h"

// using namespace std;

// class ComplexShape : public Shape{
//     public: 
//     ComplexShape(string id, vector<Shape*> shapes): Shape(id), _shapes(shapes) {}

//     double area() const {
//       double area = 0;
//       for(_it = _shapes->begin(); _it != _shapes->end(); ++_it) {
//         area += _it->area();
//       }
//       return area;
//     }

//     double perimeter() const {
//       double perimeter = 0;
//       for(_it = _shapes->begin(); _it != _shapes->end(); ++_it) {
//         perimeter += _it->perimeter();
//       }
//       return perimeter;
//     }
    
//     string info() const {
//       string info = "";
//       for(_it = _shapes->begin(); _it != _shapes->end(); ++_it) {
//         info += _it->info();
//       }
//       return info;
//     }

//     private:
//     vector<Shape*> _shapes;
//     typedef vector<Shape*>::iterator _it;

// };

// #endif
