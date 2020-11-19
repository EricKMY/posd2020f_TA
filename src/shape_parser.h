#ifndef SHAPE_PARSER
#define SHAPE_PARSER

#include <string>
#include <stack>
#include "scanner.h"

class ShapeParser {
public:
    ShapeParser(std::string input) {
        sc = new Scanner(input);
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
            buildEllipse(_arg[0], _arg[1]);
        }else if(checkRectangleVaild(token)) {
            buildRectangle(_arg[0], _arg[1]);
        }else if(checkTriangleVaild(token)) {
            buildTriangle(_arg[0], _arg[1], _arg[2], _arg[3], _arg[4], _arg[5]);
        }else if(checkCompoundShapeVaild(token)) {
            buildCompoundShapeEnd();
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
            buildCompoundShapeBegin();

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
        bool isVaild = true;

        for(int i = 0; i < 5 && isVaild; i++) {
            try {
                token = sc->nextToken();
            }catch(std::string s) {
                return false;//?
            }

            switch(i) {
                case 0:
                    isVaild = token == "(" ? true : false;
                    break;
                case 1:
                    if(!checkIsNumber(token)) isVaild = false;
                    break;
                case 2:
                    isVaild = token == "," ? true : false;
                    break;
                case 3:
                    if(!checkIsNumber(token)) isVaild = false;
                    break;
                case 4:
                    isVaild = token == ")" ? true : false;
                    break;
            }
        }

        return isVaild;
    }

    bool checkTriangleArgVaild() {
        std::string token;
        bool isVaild = true;

        token = sc->nextToken();
        if(token != "[") return false;
        if(!checkArgVaild()) return false;
        
        token = sc->nextToken();
        if(token != ",") return false;
        if(!checkArgVaild()) return false;

        token = sc->nextToken();
        if(token != ",") return false;
        if(!checkArgVaild()) return false;

        token = sc->nextToken();
        if(token != "]") return false;

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

    std::vector<std::string> getResult() {
        return _result;
    }
    
private:
    Scanner *sc;
    std::vector<std::string> _result;
    std::vector<double> _arg;

    void buildRectangle(double w, double l) {
        //use builder
        std::stringstream ss;
        ss << "Rectangle " << w << " " << l << "\n";

        _result.push_back(ss.str());
    }

    void buildEllipse(double semiMajorAxes, double semiMinorAxes) {
        //use builder
        std::stringstream ss;
        ss << "Ellipse " << semiMajorAxes << " " << semiMinorAxes << "\n";

        _result.push_back(ss.str());
    }

    void buildTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
        //use builder
        std::stringstream ss;
        ss << "Triangle " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << "\n";

        _result.push_back(ss.str());
    }

    void buildCompoundShapeBegin() {
        //use builder
        std::stringstream ss;
        ss << "CompoundShape {\n" ;
        _result.push_back(ss.str());
    }

    void buildCompoundShapeEnd() {
        //use builder
        std::stringstream ss;
        ss << "}\n" ;

        _result.push_back(ss.str());
    }
};

#endif