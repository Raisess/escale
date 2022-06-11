#pragma once

#include <iostream>
#include <functional>
#include <netinet/in.h>

class Socket {
public:
  Socket(int port, int max_conn = 5);

  void run(std::function<void(std::string)> callback);

private:
  struct sockaddr_in sock_addr;
  int sockfd;
  int sock;

  void exception(const std::string message, const int e_code = 1) const;
};
