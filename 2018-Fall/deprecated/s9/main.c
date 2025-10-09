#include <omp.h>
#include <stdio.h>

int main() {
  int i, N = 10;
  omp_set_num_threads(10);
#pragma omp parallel
  {
    for (i = 0; i < N; i++) {
      printf("%d\n", i);
    }
  }
}
