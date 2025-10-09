#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>
#include "slice.h"

#define PORT 8080

// shared queue
struct slice_t *ms;

// server socket
int server_fd;

// handler handles each incoming connection.
// It sends response and closes the connection.
void *handler(void *value) {
  char *hello = "Hello from server";
  while (1) {
    int client_socket = slice_pop(ms);
    if (client_socket != -1) {
      // writes to the client socket
      send(client_socket, hello, strlen(hello), 0);
      printf("Hello message sent\n");
    }
  }
}

// accept accepts new connections within a loop
void *acceptor(void *value) {
  struct sockaddr_in address;
  int addrlen;

  while (1) {
    // accepting client
    // accept returns client socket and fills given address and addrlen with client address information.
    int client_socket;
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }
    // adds newly accepted socket to the shared queue
    slice_push(ms, client_socket);
    printf("Hello client %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
  }
}

int main(int argc, char const *argv[]) {
  struct sockaddr_in address;

  // creates socket file descriptor
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT); // host to network -- coverts the ending of the given integer

  // binding
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listening on server socket with backlog size 3.
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
  printf("Listen on %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

  // creates shared queue
  ms = slice_new(5);

  // threads
  pthread_t taccept;
  pthread_t thandler1;
  pthread_t thandler2;
  pthread_t thandler3;

  pthread_create(&taccept, NULL, acceptor, ms);

  pthread_create(&thandler1, NULL, handler, NULL);
  pthread_create(&thandler2, NULL, handler, NULL);
  pthread_create(&thandler3, NULL, handler, NULL);
  pthread_join(thandler1, NULL);
  pthread_join(thandler2, NULL);
  pthread_join(thandler3, NULL);

  return 0;
}
