#include <iostream>
#include <fstream>
#include <string>


void readSequence(std::istream& input) {
    std::string line, name; 
    unsigned int position = 1;
    unsigned int range = 0;
    unsigned int start_position = 0;
    unsigned int end_position = 0;
    bool found_start = false;
    bool found_end = false;

    // print header
    std::cout << "id" << "\t" << "start" << "\t" << "end" << "\t" << "range" << std::endl;

    // loop through nucleotide data
    while(std::getline(input,line).good()){
      
      if(line[0] == '>'){
          name = line.substr(1);
          position = 1;
     }
      else {
          if(!line.empty()) {
            for (int i = 0; i < line.length(); i++) {
                const char currentChar = line[i];
                // the current char is 'N'?
                if(currentChar == 'N' || currentChar == 'n') {
                  // do we have a start position already
                  // if no, this is the start
                  if(found_start == false) {
                      start_position = position;
                      found_start = true;
                  }
                }
                else {
                  // the current char is no 'N' ('n')
                  // but we already had a start position
                  if(found_start == true) {
                      // so this has to be the end of the N stretch
                      end_position = position;
                      found_end = true;
                  }
                }
                // we do have both, start and end position
                // we found the whole stretch -> print and clean up for next hit
                if(found_start == true && found_end == true) {
                  const unsigned int range = end_position - start_position;
                  std::cout << name << "\t" << start_position << "\t" << end_position << "\t" << range << std::endl;
                  found_start = false;
                  found_end = false;
                }
                position++;
            }
         }
      }
   }
   // if N is last character of file
   if(found_start == true) {
     std::cout << name << "\t" << start_position << "\t" << start_position << "\t" << '1' << std::endl;
   }
}

int main(int argc, char **argv){
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
