#pragma once

#include <iostream>
#include <fstream>

class File {
public:
  File(const std::string& path);
  ~File();

  std::string read();
  void write(const std::string&);

private:
  std::string path;
  std::ifstream rfstream;
  std::ofstream wfstream;
};
