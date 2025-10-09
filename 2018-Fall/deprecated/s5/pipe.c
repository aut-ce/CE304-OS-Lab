/*
 * In The Name of God
 * =======================================
 * [] File Name : pipe.c
 *
 * [] Creation Date : 06-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * This program passes the number n that is read from the user to child process
 * child process computes n * (n + 1) / 2 and sends result to parent.
 */

int main (int argc, char *argv[]) {
  int file_des[2]; // files descriptors of the pipe
  int n;

  scanf("%d", &n);

  if (pipe(file_des) == -1) { // handles pipe error
    perror("pipe()");
    exit(EXIT_FAILURE);
  }

  switch (fork()) {
    case -1: // handles fork error
      perror("fork()");
    case 0: // child
      if (close(file_des[0]) == -1) { // close reading side of pipe
        perror("close()");
        exit(EXIT_FAILURE);
      }

      /* child writes to pipe */
      FILE *fw;

      fw = fdopen(file_des[1], "w"); // IMPORTANT convert file descriptor to FILE handler
      fprintf(fw, "%d\n", (n * (n + 1)) / 2);

      break;
    default: // parent

      if (close(file_des[1]) == -1) { // close writing side of pipe
        perror("close()");
        exit(EXIT_FAILURE);
      }

      /* parent reads from pipe */
      FILE *fr;
      int answer;

      fr = fdopen(file_des[0], "r"); // IMPORTANT convert file descriptor to FILE handler
      fscanf(fr, "%d", &answer);
      printf("%d\n", answer);

      break;
  }
}
