#include "File.h"

File::File(const std::string& path) : path(path) {}

File::~File() {}

std::string File::read() {
  this->rfstream.open(this->path);

  std::string data;
  std::string tmp;

  while (std::getline(this->rfstream, tmp)){
    data += tmp + "\n";
  }

  this->rfstream.close();

  return data;

}

void File::write(const std::string& data) {
  this->wfstream.open(this->path);
  this->wfstream << data << "\n";
  this->wfstream.close();
}
