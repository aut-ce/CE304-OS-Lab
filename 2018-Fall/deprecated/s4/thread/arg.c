/*
 * In The Name of God
 * =======================================
 * [] File Name : hello.c
 *
 * [] Creation Date : 13-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
 */
/*
 * Copyright (c)  2018 Parham Alvani.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS	5

// print_parent_stack_address is a function that is called by pthread within a new thread.
// this function print and change given value by its reference. please consider that the value
// is defined in parent stack.
// pthread functions input and output have void* format.
void *print_parent_stack_address(void *value) {
  long t = *(long *)value;
  printf("value = %ld!\n", t);
  *(long *)value = 10;
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  pthread_t thread;
  int rc;
  long t = 1373;
  rc = pthread_create(&thread, NULL, print_parent_stack_address, (void *)&t);
  if (rc != 0) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
  }
  sleep(1);
  printf("value = %ld\n", t);

  /* Last thing that main() should do */
  pthread_exit(NULL);
}
