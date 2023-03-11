#include <stdio.h>
#include <stdbool.h>

int main() {
  int a = 5, b, c = 10;
  double d = 3.14;
  char ch = 'A';
  int arr[2] = {1, 2};
  int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int cube[2][3][4][5];
  bool flag = true;

  for (int i = 0, j = 10; (i < 5 || j > 0); i++, j--) {
    if (i == 2 && j == 5) {
      printf("i: %d, j: %d\n", i, j);
    } else {
      printf("i = %d, j = %d\n", i, j);
    }
  }

  int k = 0;
  do {
    printf("k: %d\n", k);
    k++;
  } while (k < 3);

  int x = 5;
  while (x > 0) {
    printf("x: %d\n", x);
    x--;
  }

  int y = 10;
  while (y >= 0) {
    printf("y: %d\n", y);
    y--;
  }

  int z = 0;
  while (z <= 10) {
    if (z % 2 == 0) {
      printf("%d is even\n", z);
    } else {
      printf("%d is odd\n", z);
    }
    z++;
  }

  int p = 5;
  while (p > 0) {
    printf("%d\n", p--);
  }

  int q = 0;
  while (q < 5) {
    printf("%d\n", ++q);
  }

  return 0;
}
