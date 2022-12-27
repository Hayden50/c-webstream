#include <stdio.h>
#include "../server-headers/socket.h"
#define PORT 8001

int main() {
  printf("Server running on %d\n", PORT);
  
  http_socket http_s;
  create_socket(&http_s, PORT);

  return 0;
}
