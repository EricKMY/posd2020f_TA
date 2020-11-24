#ifndef SHAPE_PARSER
#define SHAPE_PARSER

#include <string>
#include <stack>
#include <deque>
#include "scanner.h"
#include "shape_builder.h"
#include <iostream>

class Shape;

class ShapeParser {
public:
    ShapeParser(std::string input): _args({}) {
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

    std::deque<Shape*> getResult() {
        return sp->getResult();
    }
    
private:
    Scanner* sc;
    ShapeBuilder* sp;
    std::vector<std::string> _result;
    std::vector<double> _args;

    void parseShape(std::string token) {
        if(isEllipse(token)) {
            sp->buildEllipse(_args[0], _args[1]);
        }else if(isRectangle(token)) {
            sp->buildRectangle(_args[0], _args[1]);
        }else if(isTriangle(token)) {
            sp->buildTriangle(_args[0], _args[1], _args[2], _args[3], _args[4], _args[5]);
        }else if(isCompoundShape(token)) {
            sp->buildCompoundShapeEnd();
        }
        _args.clear();
    }

    bool isEllipse(std::string token) {
        return token == "Ellipse" &&
               sc->nextToken() == "(" &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == ")";
    }

    bool isRectangle(std::string token) {
        return token == "Rectangle" &&
               sc->nextToken() == "(" &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == ")";
    }

    bool isTriangle(std::string token) {
        return token == "Triangle" &&
               sc->nextToken() == "(" &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == "," &&
               isNumber(sc->nextToken()) &&
               sc->nextToken() == ")";
    }

    bool isCompoundShape(std::string token) {
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

    bool isNumber(std::string token) {
        double arg;
        try {
            arg = std::stod(token.c_str());
        }catch(std::string s) {
            return false;
        }        
        _args.push_back(arg);
        return true;
    }
};

#endif