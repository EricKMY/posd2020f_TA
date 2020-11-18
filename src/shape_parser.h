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
        std::vector<double> arg;
        while(true) {
            std::string token;
            try {
                token = sc->nextToken();
            }catch(std::string s) {
                return;
            }
            
            if(token == "Ellipse") {  //Ellipse (4.000, 3.000)
                bool isVaild = true;
                for(int i = 0; i < 5 && isVaild; i++) {
                    try {
                        token = sc->nextToken();
                    }catch(std::string s) {
                        return;
                    }

                    switch(i) {
                        case 0:
                            if(sc->tokenType() != "(")
                                isVaild = false;
                        break;
                        case 1:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 2:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 3:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 4:
                            if(sc->tokenType() != ")")
                                isVaild = false;
                        break;
                    }
                }

                if(isVaild) {
                    buildEllipse(arg[0], arg[1]);
                }

                arg.clear();
            }else if(token == "Rectangle") {//Rectangle (3.000, 4.000)
                bool isVaild = true;
                for(int i = 0; i < 5 && isVaild; i++) {
                    try {
                        token = sc->nextToken();
                    }catch(std::string s) {
                        return;
                    }

                    switch(i) {
                        case 0:
                            if(sc->tokenType() != "(")
                                isVaild = false;
                        break;
                        case 1:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 2:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 3:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 4:
                            if(sc->tokenType() != ")")
                                isVaild = false;
                        break;
                    }
                }

                if(isVaild) {
                    buildRectangle(arg[0], arg[1]);
                }

                arg.clear();
            }else if(token == "Triangle") {//Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])
                bool isVaild = true;
                for(int i = 0; i < 19 && isVaild; i++) {
                    try {
                        token = sc->nextToken();
                    }catch(std::string s) {
                        return;
                    }

                    // too long!
                    switch(i) {
                        case 0:
                            if(sc->tokenType() != "(")
                                isVaild = false;
                        break;
                        case 1:
                            if(sc->tokenType() != "[")
                                isVaild = false;
                        break;
                        case 2:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 3:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 4:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 5:
                            if(sc->tokenType() != "]")
                                isVaild = false;
                        break;
                        case 6:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 7:
                            if(sc->tokenType() != "[")
                                isVaild = false;
                        break;
                        case 8:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 9:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 10:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 11:
                            if(sc->tokenType() != "]")
                                isVaild = false;
                        break;
                        case 12:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 13:
                            if(sc->tokenType() != "[")
                                isVaild = false;
                        break;
                        case 14:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 15:
                            if(sc->tokenType() != ",")
                                isVaild = false;
                        break;
                        case 16:
                            if(sc->tokenType() != "NUMBER")
                                isVaild = false;
                            arg.push_back(std::stod(token.c_str())); // number
                        break;
                        case 17:
                            if(sc->tokenType() != "]")
                                isVaild = false;
                        break;
                        case 18:
                            if(sc->tokenType() != ")")
                                isVaild = false;
                        break;
                    }
                }

                if(isVaild) {
                    buildTriangle(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5]);
                }

                arg.clear();
            }else if(token == "CompoundShape") {  //CompoundShape {Ellipse (4.000, 3.000)}
                // call buildCompoundShapeBegin();
                buildCompoundShapeBegin();
            }else if(token == "}") { // compoundShapeEnd;
                buildCompoundShapeEnd();
            }

        }
    }

    std::vector<std::string> getResult() {

        return _result;
    }


private:
    Scanner *sc;
    std::vector<std::string> _result;
    std::stack<std::string> _stack;

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

    void buildTriangle(double c1, double c2, double c3, double c4, double c5, double c6) {
        //use builder
        std::stringstream ss;
        ss << "Triangle " << c1 << " " << c2 << " " << c3 << " " << c4 << " " << c5 << " " << c6 << "\n";

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