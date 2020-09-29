#include <fstream>
#include <string>
#include "./terminal.h"

using namespace std;

int main(int argc, char **argv) {
      if(argc != 5) {return 0;}
      string line = "";
      string result = "";
      ifstream inputfile(argv[1]);
      ofstream outputfile(argv[2]);
      if (inputfile.is_open() && outputfile.is_open()) {
            while (getline(inputfile, line)){
                  result += line + " ";
            }
            result += argv[3];
            result += " ";
            result += argv[4];
            Terminal terminal(result);
            outputfile << terminal.showResult();
            inputfile.close();
            outputfile.close();
      }
};