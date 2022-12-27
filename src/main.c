#include <stdio.h>
#include <sys/socket.h>

int main() {
  printf("Hello World\n");
  int client_socket = socket(AF_LOCAL, SOCK_STREAM, 0);
  return 0;
}
