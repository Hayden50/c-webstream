#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/_endian.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8001);
  
  // Sets IP of server to connect to and converts to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) < 0) {
    printf("Binary conversion failed\n");
    return 0;
  }

  // Connects to server using client socket and server socket data
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    printf("Connection Failed\n");
    return 0;
  }

  printf("Connection Successful\n");

  char *buffer = "Hello World";
  write(client_socket, (void *)buffer, strlen(buffer));

  return 0;
}
