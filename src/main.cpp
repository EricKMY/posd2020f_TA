#include <iostream>
#include <fstream> 
#include "./terminal.h"

using namespace std;

int main(int argc, char *argv[]) {

    string input_str, line_str;
    ifstream input_file (argv[1]);

    if (input_file.is_open())
    {
        while ( getline (input_file,line_str) )
        {
            input_str += line_str;
        }
        input_file.close();
    
    }else cout << "Unable to open file";

    cout << input_str << endl;

    input_str.append(" ");
    input_str.append(argv[3]);
    input_str.append(" ");
    input_str.append(argv[4]);
    input_str.append(" ");
    input_str.append(argv[5]);

    Terminal * terminal;
    try{
        terminal = new Terminal(input_str);

    }catch(std::string errorMessage){
        cout << errorMessage << endl;
    }
 
    cout << terminal->showResult() << endl;

    ofstream output_file (argv[2]);
    if (output_file.is_open())
    {
        output_file << terminal->showResult();
        
        output_file.close();
    
    }else cout << "Unable to open file";

    return 0;
}
