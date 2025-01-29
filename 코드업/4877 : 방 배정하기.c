#include <stdio.h>

int main() {
  int a, b, c, d;
  int i, j, k;

  scanf("%d %d %d %d", &a, &b, &c, &d);

  for (i = 0; i <= d; i += a) {
    for (j = 0; j <= d; j += b) {
      for (k = 0; k <= d; k += c) {
        if (i + j + k == d) {
          printf("1");
          return 0;
        }
      }
    }
  }
  printf("0");
  return 0;
}