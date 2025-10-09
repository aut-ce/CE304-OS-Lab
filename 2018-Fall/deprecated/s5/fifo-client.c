/*
 * In The Name of God
 * =======================================
 * [] File Name : fifo-client.c
 *
 * [] Creation Date : 06-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */

#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

/*
 * This program opens a pipe that is builded by fifo-server.c and writes user input
 * to it.
 */

int main(int argc, char *argv[]) {
  int n;
  FILE *server;

  server = fopen("/tmp/parham_fifo_sv", "w"); // opens fifo to write

  do { // reads user input until it is not equal to zero
    scanf("%d", &n);
    printf("You entered: %d\n", n);
    fprintf(server, "%d\n", n); // writes user input to fifo
    fflush(server); // and flushes it
  } while (n != 0);
}
