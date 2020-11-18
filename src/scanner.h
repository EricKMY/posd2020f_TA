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
            switch(_currState) {
                case START_STATE:
                    if (isLetter(c)) {
                        //change state;
                        _bufferStr += {c};
                        _currState = IDENTIFIER_SHAPE_STATE;
                    }else if(isNumber(c)) {
                        _bufferStr += {c};
                        _currState = IDENTIFIER_NUMBER_STATE;
                    }else {
                        switch(c) {
                            case '(':
                            case ')':
                            case ',':
                            case '{':
                            case '}':
                            case '[':
                            case ']':
                                _tokenType = {c};
                                return {c};
                            default:
                            break;
                        }
                    }
                break;
                case IDENTIFIER_SHAPE_STATE:
                    if (isLetter(c)) {
                        _bufferStr += {c};
                    }else {
                        //change state;
                        _currPos--; //retract.
                        _currState = START_STATE;
                        std::string compare_str = _bufferStr;
                        _bufferStr = "";

                        if (isShape(compare_str)) {
                            _tokenType = "SHAPE";
                            return compare_str;
                        }
                    }
                break;

                case IDENTIFIER_NUMBER_STATE:
                    if(isNumber(c)) {
                        _bufferStr += {c};
                    }else {
                        _currPos--; //retract.
                        _currState = START_STATE;
                        std::string number = _bufferStr;

                        _bufferStr = "";
                        _tokenType = "NUMBER";
                        return number;
                    }
                break;
            }
        }

        return _bufferStr;
    }

    std::string tokenType() {
        return _tokenType;
    }

private:
    std::string _input;
    std::string _bufferStr;
    int _currPos;
    int _currState;
    std::string _tokenType;

    char nextChar() {
        if(_currPos >= _input.size()) {
            throw std::string("next char doesn't exist.");
        } else { 

            return _input.c_str()[_currPos++];
        }
    }


    bool isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    bool isNumber(char c) {
        return (c >= '0' && c <= '9') || c =='.' || c == '-';
    }

    bool isShape(std::string s) {
        return s == "CompoundShape" || s == "Ellipse" || s == "Rectangle" || s == "Triangle";
    }

    static const int START_STATE  = 0;
    static const int IDENTIFIER_SHAPE_STATE = 1;
    static const int IDENTIFIER_NUMBER_STATE = 2;
};

#endif
