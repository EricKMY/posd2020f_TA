#ifndef TERMINAL_H
#define TERMINAL_H

#include <vector>
#include <regex>
#include "./shape.h"
#include "./sort.h"
#include "./ellipse.h"
#include "./triangle.h"
#include "./rectangle.h"
#include "./two_dimensional_coordinate.h"

using namespace std;

class Terminal {
    public:
    Terminal(string input) {
        regex split_space("[^\\s]+"); // 

        regex shape_close_paren(".*[)]"); // 
        
        regex check_paramter_valid("^[(][\\[\\]0-9,.-]+[)]");

        regex split_paramter("[^\\s,()\\[\\]]+"); //  

        std::sregex_iterator words_begin = sregex_iterator(input.begin(),input.end(), split_space);
        std::sregex_iterator words_end = std::sregex_iterator();

        std::string param_str;
        

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;                                                 
            std::string match_str = match.str(); 
            
            if(_stage == 0){

                if(match_str == "Ellipse" || match_str == "Triangle" || match_str ==  "Rectangle"){
                    _shape_str_vector.push_back(match_str);
                    _stage ++;  
                
                }else if(_feature_stage == 0 && (match_str == "area" || match_str == "perimeter" || match_str == "sumOfSquares")){
                    _sort_feature_str = match_str;
                    _feature_stage ++;
                }else if(_feature_stage == 1 && (match_str == "asc" || match_str == "des")){
                    _order_feature_str = match_str;
                    _feature_stage ++;
                }else if(match_str == "area" || match_str == "perimeter" || match_str == "info"){
                    _show_feature_str = match_str;
                }
            }else if(_stage == 1){
                param_str += match_str;
                if(regex_match(match_str , shape_close_paren)){
                    if(regex_match(param_str, check_paramter_valid)){
                        _shape_str_vector.push_back(param_str);

                    }else{
                        _shape_str_vector.erase(_shape_str_vector.end() - 1);
                        
                    }
                    _stage --;
                    param_str = "";
                }
            }
        }  

        if(_order_feature_str == "" || _sort_feature_str == "" || _show_feature_str == "" || _shape_str_vector.size() == 0){
            throw string("invalid input");
        }



        for(std::vector<string>::iterator str_it = _shape_str_vector.begin(); str_it != _shape_str_vector.end(); str_it++){
                vector<double> param_vector;

                if(*str_it == "Ellipse"){
                    str_it ++;
                    std::sregex_iterator words_begin = sregex_iterator((*str_it).begin(),(*str_it).end(), split_paramter);
                    std::sregex_iterator words_end = std::sregex_iterator();

                    if(std::distance(words_begin,words_end) != 2){
                        continue;
                    }

                    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                        std::smatch match = *i;
                        std::string match_str = match.str();

                        param_vector.push_back(std::atof(match_str.c_str()));
                    }

                    Shape *shape;
                    try {
                        shape = new Ellipse(param_vector.at(0), param_vector.at(1));
                    }catch(string e) {
                        throw string("invalid input");
                    }

                    _shape_vector.push_back(shape);
                    
                }else if(*str_it == "Triangle"){
                    str_it ++;

                    std::sregex_iterator words_begin = sregex_iterator((*str_it).begin(),(*str_it).end(), split_paramter);
                    std::sregex_iterator words_end = std::sregex_iterator();

                    if(std::distance(words_begin,words_end) != 6){
                        continue;
                    }

                    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                        std::smatch match = *i;
                        std::string match_str = match.str();

                        param_vector.push_back(std::atof(match_str.c_str()));
                    }

                    vector<TwoDimensionalCoordinate*> triangleExceptionVector;
                    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(param_vector.at(0), param_vector.at(1)));
                    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(param_vector.at(2), param_vector.at(3)));
                    triangleExceptionVector.push_back(new TwoDimensionalCoordinate(param_vector.at(4), param_vector.at(5)));
                   

                    _shape_vector.push_back(new Triangle(triangleExceptionVector));

                }
                else if(*str_it == "Rectangle"){

                    str_it ++;
                    std::sregex_iterator words_begin = sregex_iterator((*str_it).begin(),(*str_it).end(), split_paramter);
                    std::sregex_iterator words_end = std::sregex_iterator();

                    if(std::distance(words_begin,words_end) != 2){
                        continue;
                    }

                    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
                        std::smatch match = *i;
                        std::string match_str = match.str();

                        param_vector.push_back(std::atof(match_str.c_str()));
                    }


                    Shape *shape;
                    try {
                        shape = new Rectangle(param_vector.at(0), param_vector.at(1));
                    }catch(string e) {
                        throw string("invalid input");
                    }

                    _shape_vector.push_back(shape);
                }
        }

        if(_shape_vector.size() == 0) {
            throw string("invalid input");
        }

    }

    string showResult() {
        Sort *sort = new Sort(&_shape_vector);

        if(_order_feature_str == "asc"){
            AscendingCompare ascendingCompare(_sort_feature_str);
            sort->standardSort(ascendingCompare);

        }else if(_order_feature_str == "des"){
            DescendingCompare descendingCompare(_sort_feature_str);
            sort->standardSort(descendingCompare);
        }

        _result = "";
        for(std::vector<Shape *>::iterator it = _shape_vector.begin(); it != _shape_vector.end(); it++){
            if(_show_feature_str == "area"){
                char area[10];
                sprintf(area, "%.3f", (*it)->area());
                _result += area;

            }else if(_show_feature_str == "perimeter"){  
                char perimeter[10];
                sprintf(perimeter, "%.3f", (*it)->perimeter());
                _result += perimeter;

            }else if(_show_feature_str == "info"){
                
                _result += (*it)->info();
            }

            if(it + 1 != _shape_vector.end()){
                _result += "\n";
            }
        }

        return _result;
    }

    private:
        int _stage;
        vector<string> _shape_str_vector;
        vector<Shape *> _shape_vector;

        string _sort_feature_str;
        string _order_feature_str;
        string _show_feature_str;
        int _feature_stage = 0;


        string _result;

};


#endif