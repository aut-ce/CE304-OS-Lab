/*
 * In The Name of God
 * =======================================
 * [] File Name : slice.h
 *
 * [] Creation Date : 20-11-2018
 *
 * [] Created By : Parham Alvani <parham.alvani@gmail.com>
 * =======================================
*/
/*
* Copyright (c)  2018 Parham Alvani.
*/
#ifndef SLICE_H
#define SLICE_H

#include <pthread.h>

// slice_t is a simple queue that have push and pop methods.
struct slice_t {
    int size; // underline array size
    int start; // start position of quque
    int end; // end position of quque
    int non_empty; // number of the non empty cells in queue
    int *values; // underline array
    pthread_mutex_t lock; // handles concurrent accesses
};

// slice_new creates new slice and returns its address
struct slice_t *slice_new(int size);

// slice_push pushes given value into given slice
void slice_push(struct slice_t *, int);
// slice_pop pops from given slice
int slice_pop(struct slice_t *);

#endif
