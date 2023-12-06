#include <vector>
#include <string>

bool contains_N(const std::string& str) {
  return(str.find("N") != std::string::npos || str.find("n") != std::string::npos);
}

class hitCollector {
  public:
    std::string chr;
    unsigned int start;
    unsigned int end;
    hitCollector(std::string chr_, unsigned int start_, unsigned int end_) {
      chr = chr_;
      start = start_;
      end = end_;
    }
    void print(void) {
      std::cout << chr << "\t" << start << "\t" << end << "\n";
    }
};
void (hitCollector::*print)(void) = &hitCollector::print; // call member function of class instance

void showHits(std::vector<hitCollector*> &hc) {
  if(!hc.empty()) for (auto i: hc) (i->*print)();
  hc.clear();
}

void readSequence(std::istream &input) {
  std::vector<hitCollector*> vec;

  std::string line, name;
  unsigned int position;
  unsigned int start_position = 0;
  unsigned int end_position = 0;
  bool found_start = false;
  bool found_end = false;

  // loop through nucleotide data
  while (std::getline(input, line).good()) {
    if (line.find(">") == 0) {
      // was the last character of the previous sequence an 'N'?
      if (found_start == true) {
        vec.push_back(new hitCollector(name, start_position, start_position));
        found_start = false;
        found_end = false;
      }
	  // show hits of previous sequence
      showHits(vec);

      name = line.substr(1);
      position = 0;
    }
    else if (line.find(";") == 0) continue;
    else {
      if (!line.empty()) {
        if (!(contains_N(line))) {
          position += line.length();
          continue;
        }
        for (int i = 0; i < line.length(); i++) {
          const char *currentChar = &line[i];
          // the current char is 'N'?
          //78 = 'N' and 100 = 'n'
          if (*currentChar == 78 || *currentChar == 110) {
            // do we have a start position already?
            // if no, this is the start
            if (found_start == false) {
              start_position = position;
              found_start = true;
            }
          }
          else {
            // the current char is no 'N' ('n')
            // but we already had a start position
            if (found_start == true) {
              // so this has to be the end of the N stretch
              end_position = position - 1;
              found_end = true;
            }
          }
          // we do have both, start and end position
          // we found the whole stretch -> print and clean up for next hit
          if (found_start == true && found_end == true) {
            //const unsigned int range = end_position == start_position ? 1 : (end_position + 1) - start_position;
            vec.push_back(new hitCollector(name, start_position, end_position));
            found_start = false;
            found_end = false;
          }
          position++;
        }
      }
    }
  }
  // if N is last character of file
  if (found_start == true) {
    vec.push_back(new hitCollector(name, start_position, start_position));
    showHits(vec);
  }
}
