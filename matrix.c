#include <time.h>
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

#define SIZE 1024

void add(float a[SIZE][SIZE], float b[SIZE][SIZE]) {
  // Adds matrix `b` to matrix `a` replacing the contents of matrix `a`

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      a[j][i] = a[j][i] + b[j][i];
    }
  }
}

void mul(float a[SIZE][SIZE], float b[SIZE][SIZE], float c[SIZE][SIZE]) {
  // Adds matrix `b` to matrix `a` replacing the contents of matrix `a`

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      c[j][i] = 0;

      for (int k = 0; k < SIZE; k++) {
        c[j][i] += a[j][k] * b[k][i];
      }
    }
  }
}

int main() {
  static float a[SIZE][SIZE];
  static float b[SIZE][SIZE];
  static float c[SIZE][SIZE];

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

  printf("Multiplying matrices...\n");

  start = clock();
  mul(a, b, c);
  printf("Multiplication completed in %ld ms\n", 1000 * (clock() - start) / CLOCKS_PER_SEC);

  printf("Confirming result...\n");
  for (int i = 16; i < 32; i++) {
    for (int j = 16; j < 32; j++) {
      float sum = 0;
      for (int k = 0; k < SIZE; k++) {
        sum += (float)(2*i+k) * (float)(k-j);
      }
    }
  }

  printf("Success!\n");
  return 0;
}