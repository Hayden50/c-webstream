#include <stdio.h>
#include <unistd.h>
#include "../server-headers/socket.h"
#define PORT 8001

int main() {
  setbuf(stdout, NULL);
  
  // Socket bound and listening at localhost:PORT
  http_socket http_s;
  create_socket(&http_s, PORT);

  int new_socket = accept(http_s.socket, NULL, NULL);

  char buffer[1024];
  read(new_socket, buffer, 1024);
  printf("%s\n", buffer);

  return 0;
}
