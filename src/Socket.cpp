#include "./Socket.h"

Socket::Socket(int port, int max_conn) {
  this->socfd = socket(1, 1, 1);
  this->soc = bind(this->socfd, addr, len);

  listen(this->socfd, 1);
}

void Socket::run(std::function<void(void)> callback) {
  while (true) {
    if (accept(this->socfd, addr, len)) {
      callback();
    }
  }
}
