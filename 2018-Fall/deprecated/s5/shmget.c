/*
 * In The Name of God
 * =======================================
 * [] File Name : shmget.c
 *
 * [] Creation Date : 06-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, const char *argv[]) {
  int shmid;
  key_t key = 0x01020304;

  // create 4096 bytes of shared memory
  shmid = shmget(key, 4096, IPC_CREAT);
  if (shmid < 0) {
    fprintf(stderr, "failed to create shm segment\n");
    perror("shmget");
    return -1;
  }

  printf("created %d\n", shmid);
  return 0;
}
