#include "File.h"

std::string File::read() {
  this->rfstream.open(this->path);

  std::ostrstream data;
  std::string tmp;

  while (std::getline(this->rfstream, tmp)){
    data << tmp << "\n";
  }

  this->rfstream.close();

  return data.str();

}

void File::write(std::string data) {
  this->wfstream.open(this->path);
  this->wfstream << data << "\n";
  this->wfstream.close();
}
