/*
 * In The Name of God
 * =======================================
 * [] File Name : slice.c
 *
 * [] Creation Date : 20-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#include "slice.h"

#include <stdlib.h>
#include <pthread.h>

struct slice_t *slice_new(int size) {
  struct slice_t *s = malloc(sizeof(struct slice_t));
  s->size = size;
  s->start = 0;
  s->end = 0;
  s->non_empty = 0;
  pthread_mutex_init(&s->lock, NULL);
  s->values = malloc(sizeof(int) * size);

  return s;
}

void slice_push(struct slice_t *this, int value) {
  if (this->non_empty == this->size) {
    return;
  }
  this->non_empty++;
  this->values[this->end] = value;
  this->end = (this->end + 1) % this->size;
}

int slice_pop(struct slice_t *this) {
  if (this->non_empty == 0) {
    return 0;
  }
  this->non_empty--;
  int value = this->values[this->start];
  this->start = (this->start + 1) % this->size;
  return value;
}
