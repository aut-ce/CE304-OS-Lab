/*
 * In The Name Of God
 * ========================================
 * [] File Name : code-code.c
 *
 * [] Creation Date : 23-11-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2016 Parham Alvani.
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int x = 1;

  pid = fork();

  if (pid < 0) { // handles fork error
    perror("fork()");
    exit(EXIT_FAILURE);
  } else if (pid == 0) { // child process
    printf("child has x = %d\n", ++x);
    exit(-12);
  } else { // parent process
    printf("parent has x = %d\n", --x);
    int sts;
    wait(&sts);
    printf("child is dead (%d)\n", WEXITSTATUS(sts));
  }
  exit(EXIT_SUCCESS);
}
