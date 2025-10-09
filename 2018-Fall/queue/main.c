/*
 * In The Name of God
 * =======================================
 * [] File Name : main.c
 *
 * [] Creation Date : 20-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "slice.h"

#define NUM_THREADS 5

void *run(void *arg) {
  struct slice_t *s = (struct slice_t *) arg;

  slice_push(s, 10);
  printf("%d\n", slice_pop(s));

  return NULL;
}

int main(int argc, const char *argv[]) {
  struct slice_t *s = slice_new(10);

  pthread_t threads[NUM_THREADS];

  int t;
  int rc;
  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_create(&threads[t], NULL, run, (void *)s);
    if (rc != 0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
  }

  for (t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }

  if (s->non_empty != 0) {
    printf("invalid queue state, non_empty = %d != 0\n", s->non_empty);
    exit(EXIT_FAILURE);
  }

  if (s->start != NUM_THREADS || s->end != NUM_THREADS) {
    printf("invalid queue state, start = %d != %d || end = %d != %d\n", s->start, NUM_THREADS, s->end, NUM_THREADS);
    exit(EXIT_FAILURE);
  }

}
