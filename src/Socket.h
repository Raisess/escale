#pragma once

#include <iostream>
#include <functional>
#include <sys/socket.h>

class Socket {
public:
  Socket(int port, int max_conn);

  void run(std::function<void(void)> callback);

private:
  int socfd;
  int soc;
};
