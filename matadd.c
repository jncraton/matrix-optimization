#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

#define SIZE 16384

void add(int a[SIZE][SIZE], int b[SIZE][SIZE]) {
  // Adds matrix `b` to matrix `a` replacing the contents of matrix `a`

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      a[j][i] = a[j][i] + b[j][i];
    }
  }
}

int main() {
  static int a[SIZE][SIZE];
  static int b[SIZE][SIZE];

  printf("Initializing matrices...\n");

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      a[i][j] = i+2*j;
      b[i][j] = i-j; 
    }
  }

  printf("Adding matrices...\n");

  clock_t start = clock();
  add(a, b);
  printf("Addition completed in %ld ms\n", 1000 * (clock() - start) / CLOCKS_PER_SEC);

  printf("Confirming result...\n");
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      assert(a[i][j] == 2*i+j);
    }
  }

  printf("Success!\n");
  return 0;
}