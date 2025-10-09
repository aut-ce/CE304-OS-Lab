#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
 * here we are going to see a normal distribution from binomial distribution for a large n
 */

const int k = 10; // create 10 process then wait for their results

int gen();
void print_his(int[25]);

int main() {
  int n;
  int i, j;
  int his[25];
  for (i = 0; i < 25; i++) {
    his[i] = 0;
  }
  scanf("%d", &n);
  for (i = 0; i < n; i += k) {
    for (j = 0; j < k; j++) {
      srand(i + j + time(0));
      pid_t pid = fork();
      if (pid == 0) {
        int ret = gen();
        exit(ret + 12);
      } else if (pid > 0) {
      } else {
        perror("fork failed");
      }
    }
    for (j = 0; j < k; j++) {
      int ret;
      wait(&ret);
      ret = WEXITSTATUS(ret);
      his[ret]++;
    }
  }
  print_his(his);
}

// print_his print the histogram chart of the collected data
void print_his(int his[25]) {
  int i, j;

  for (i = 0; i < 25; i++) {
    printf("%d: ", i - 12);
    for (j = 0; j < his[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}

// gen generates 12 numbers between 0 to 100 then compare them with 49 and return a counter with
// the following conditions
// if n <= 49 => count--
// if n > 49 => count++
int gen() {
  int count = 0;
  int i;
  for (i = 0; i < 12; i++) {
    int n = rand() % 100;
    if (n <= 49) {
      count--;
    } else {
      count++;
    }
  }
  return count;
}
