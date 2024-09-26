#include <iostream>
#include <fstream>
#include "parse.h"
#include <sys/stat.h>
#include <bits/stdc++.h>

bool file_exists(const std::string &filepath) {
  struct stat buffer;
  return (stat(filepath.c_str(), &buffer) == 0);
}

int main(int argc, char **argv){
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  if (argc == 2) {
    if (file_exists(argv[1])) {
      std::ifstream ifile(argv[1]);
      // read from file
      readSequence(ifile);
    }
    else {
      std::cout << "Provided file does not exists" << std::endl;
    }
  }
  else {
    // read from stdin
    readSequence(std::cin);
  }
  return 0;
}
