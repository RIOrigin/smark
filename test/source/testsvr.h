#pragma once
#include <ae.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/tcp.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <memory>
#include <stdexcept>

#if defined(__linux__)
#  include <linux/version.h>
#endif

namespace smark_tests {
  class TestServer {
  public:
    const int kMaxConns = 20;
    TestServer();
    ~TestServer();
    void Connect(uint16_t listen_port = 3000);
    void Run();

  private:
    int sock_fd_;
  };
}  // namespace smark_tests
