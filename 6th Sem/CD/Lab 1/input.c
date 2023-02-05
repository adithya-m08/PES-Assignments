#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  int c = a + b;
  if (c > 25) {
    printf("The sum of %d and %d is greater than 25\n", a, b);
  } else {
    printf("The sum of %d and %d is less than or equal to 25\n", a, b);
  }

  int i = 0;
  while (i < 5) {
    printf("The value of i is %d\n", i);
    i++;
  }

  return 0;
}
