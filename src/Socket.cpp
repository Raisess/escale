#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "./Socket.h"

Socket::Socket(int port, int max_conn) {
  this->sock_addr.sin_family = AF_INET;
  this->sock_addr.sin_addr.s_addr = INADDR_ANY;
  this->sock_addr.sin_port = htons(port);

  this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (this->sockfd < 0) {
    this->exception("Error: fail opening socket");
  }

  this->sock = bind(this->sockfd, (struct sockaddr*) &this->sock_addr, sizeof(this->sock_addr));
  if (this->sock < 0) {
    this->exception("Error: fail binding socket");
  }

  listen(this->sockfd, max_conn > 5 ? 5 : max_conn);
}

void Socket::run(std::function<void(std::string)> callback) {
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  char msg_buffer[256];

  while (true) {
    int conn = accept(this->sockfd,(struct sockaddr*) &client_addr, &client_addr_len);

    if (conn < 0) {
      this->exception("Error: fail accepting connection");
    }

    bzero(msg_buffer, 256);
    int n = read(conn, msg_buffer, 255);

    if (n > 0) {
      callback(msg_buffer);
    }
  }
}

void Socket::exception(const std::string message, const int e_code) const {
  std::cout << message << std::endl;
  exit(e_code);
}
