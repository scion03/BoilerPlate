
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

int main()
{
  // create socket
  int client_socket;
  client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // define server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9002);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // connect to the server
  int connection_status = connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address));
  if (connection_status == -1)
  {
    cout << "error in connection" << endl;
  }

  // receive data from the server
  char server_response[256];
  recv(client_socket, &server_response, sizeof(server_response), 0);

  // print out the server's response
  cout << "server's response: " << server_response << endl;

  // close the socket
  close(client_socket);

  return 0;
}