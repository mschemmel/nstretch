#include <iostream>
#include <fstream>
#include <string>
#include "parse.h"

int main(int argc, char **argv){

    // print header
    std::cout << "id" << "\t" << "start" << "\t" << "end" << "\t" << "range" << std::endl;

    if( argc > 1 ){
      // read from file
      std::ifstream ifile(argv[1]);
      readSequence(ifile);  
    }
    else {
      // read from stdin
      readSequence(std::cin);
    }
    return 0;
}
