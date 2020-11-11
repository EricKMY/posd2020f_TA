#ifndef SCANNER_H
#define SCANNER_H

class Scanner {
public:
    Scanner(std::string input):_input(input) {
        _currPos = 0;
        _bufferStr = "";
        _currState = START_STATE;
    }

    std::string nextToken() {
        while(true) {
            char c = nextChar(); // if no char throw exception "next char doesn't exist."
            //can use state pattern after scanner finished.
            switch(_currState) {
                case START_STATE:
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                        //change state;
                        _bufferStr += {c};
                        _currState = IDENTIFIER_STATE;
                    }else {
                        switch(c) {
                            case '{':
                                return {c};
                            case '}':
                                return {c};
                            default:
                            break;
                        }
                    }
                break;
                case IDENTIFIER_STATE:
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                        _bufferStr += {c};
                    }else {
                        //change state;
                        _currPos--; //retract.
                        _currState = START_STATE;

                        if(_bufferStr == "CompoundShape") {
                            _bufferStr = "";
                            return "CompoundShape";
                        }else if(_bufferStr == "Ellipse") {
                            _bufferStr = "";
                            return "Ellipse";
                        }else if(_bufferStr == "Rectangle") {
                            _bufferStr = "";
                            return "Rectangle";
                        }else if(_bufferStr == "Triangle") {
                            _bufferStr = "";
                            return "Triangle";
                        }

                        _bufferStr = "";
                    }
                break;
            }
        }

        return _bufferStr;
    }

private:
    std::string _input;
    std::string _bufferStr;
    int _currPos;
    int _currState;

    char nextChar() {
        if(_currPos >= _input.size()) {
            throw std::string("next char doesn't exist.");
        } else { 

            return _input.c_str()[_currPos++];
        }
    }


    static const int START_STATE  = 0;
    static const int IDENTIFIER_STATE = 1;
};

#endif
