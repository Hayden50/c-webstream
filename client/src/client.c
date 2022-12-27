#include <stdio.h>
#include <sys/socket.h>

int main() {
  int client_socket = socket(AF_LOCAL, SOCK_STREAM, 0);
  return 0;
}
