#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }
int main() {
  int k, c;
  scanf("%d %d", &k, &c);

  for (int i = 0; i < c; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    int rest = k - max(a, b);
    if ((a >= b && a - rest - b > 2) || (a < b && b - rest - a > 1))
      printf("0\n");
    else
      printf("1\n");
  }

  return 0;
}