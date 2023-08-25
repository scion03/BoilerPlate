//
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
using namespace std;

int main()
{
  // creating socket
  int server_socket;
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // defining server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // binding the socket to our specified IP and port
  bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

  // listening
  listen(server_socket, 5);

  // accepting the connection
  int client_socket;
  client_socket = accept(server_socket, NULL, NULL);

  // const void* msg = "Hello Client";
  // sending the message
  send(client_socket, "Hello Client", sizeof("Hello Client"), 0);

  close(server_socket);

  return 0;
}