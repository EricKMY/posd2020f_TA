#ifndef SHAPE_PARSER
#define SHAPE_PARSER

#include <string>
#include <stack>
#include "scanner.h"
#include "shape_builder.h"

class Shape;

class ShapeParser {
public:
    ShapeParser(std::string input) {
        sc = new Scanner(input);
        sp = new ShapeBuilder();
    }

    void parser() {
        while(true) {
            std::string token;

            try {
                token = sc->nextToken();
            }catch(std::string s) {
                return;
            }
            
            parseShape(token);
        }
    }

    void parseShape(std::string token) {
        _arg.clear();
        if(checkEllipseVaild(token)) {
            sp->buildEllipse(_arg[0], _arg[1]);
        }else if(checkRectangleVaild(token)) {
            sp->buildRectangle(_arg[0], _arg[1]);
        }else if(checkTriangleVaild(token)) {
            sp->buildTriangle(_arg[0], _arg[1], _arg[2], _arg[3], _arg[4], _arg[5]);
        }else if(checkCompoundShapeVaild(token)) {
            sp->buildCompoundShapeEnd();
        }
    }

    bool checkEllipseVaild(std::string token) {
        if(token == "Ellipse") {
            if(checkArgVaild()) {
                return true;
            }
        }
        return false;
    }

    bool checkRectangleVaild(std::string token) {
        if(token == "Rectangle") {
            if(checkArgVaild()) {
                return true;
            }
        }
        return false;
    }

    bool checkTriangleVaild(std::string token) {
        if(token == "Triangle") {
            if(checkTriangleArgVaild()) {
                return true;
            }
        }
        return false;
    }

    bool checkCompoundShapeVaild(std::string token) {
        if(token == "CompoundShape") {
            sp->buildCompoundShapeBegin();

            token = sc->nextToken();
            if(token != "{") return false;

            token = sc->nextToken();
            while(token != "}") {
                parseShape(token);
                token = sc->nextToken();
            }
            return true;
        }
        
        return false;
    }

    bool checkArgVaild() {
        std::string token;

        token = sc->nextToken();
        if(token != "(") return false;

        if(!checkNumberPairVaild()) return false;

        token = sc->nextToken();
        if(token != ")") return false;

        return true;
    }

    bool checkTriangleArgVaild() {
        std::string token;

        token = sc->nextToken();
        if(token != "(") return false;

        if(!checkNumberPairVaild()) return false;

        token = sc->nextToken();
        if(token != ",") return false;

        if(!checkNumberPairVaild()) return false;

        token = sc->nextToken();
        if(token != ",") return false;

        if(!checkNumberPairVaild()) return false;

        token = sc->nextToken();
        if(token != ")") return false;

        return true;
    }

    bool checkNumberPairVaild() {
        std::string token;
        token = sc->nextToken();
        if(!checkIsNumber(token)) return false;

        token = sc->nextToken();
        if(token != ",") return false;

        token = sc->nextToken();
        if(!checkIsNumber(token)) return false;

        return true;
    }

    bool checkIsNumber(std::string token) {
        double d;
        try {
            d = std::stod(token.c_str());
        }catch(std::string s) {
            return false;
        }        
        _arg.push_back(d);
        return true;
    }

    std::stack<Shape*> getResult() {
        return sp->getResult();
    }
    
private:
    Scanner *sc;
    ShapeBuilder* sp;
    std::vector<std::string> _result;
    std::vector<double> _arg;

    // void buildRectangle(double w, double l) {
    //     //use builder
    //     std::stringstream ss;
    //     ss << "Rectangle " << w << " " << l << "\n";

    //     _result.push_back(ss.str());
    // }

    // void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
    //     //use builder
    //     std::stringstream ss;
    //     ss << "Ellipse " << semiMajorAxes << " " << semiMinorAxes << "\n";

    //     _result.push_back(ss.str());
    // }

    // void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    //     //use builder
    //     std::stringstream ss;
    //     ss << "Triangle " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";

    //     _result.push_back(ss.str());
    // }

    // void buildCompoundShapeBegin() {
    //     //use builder
    //     std::stringstream ss;
    //     ss << "CompoundShape {\n" ;
    //     _result.push_back(ss.str());
    // }

    // void buildCompoundShapeEnd() {
    //     //use builder
    //     std::stringstream ss;
    //     ss << "}\n" ;

    //     _result.push_back(ss.str());
    // }
};

#endif