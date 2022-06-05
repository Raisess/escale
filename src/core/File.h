#pragma once

#include <iostream>
#include <fstream>
#include <strstream>

class File {
public:
  File(std::string path) {
    this->path = path;
  }

  std::string read();
  void write(std::string data);

private:
  std::string path;
  std::ifstream rfstream;
  std::ofstream wfstream;
};
