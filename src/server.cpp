#include <iostream>
#include "Socket.h"

int main() {
  Socket* server = new Socket(8080);

  server->run([](std::string message) -> void {
    std::cout << "Message received: " << message << std::endl;
  });

  return 0;
}
