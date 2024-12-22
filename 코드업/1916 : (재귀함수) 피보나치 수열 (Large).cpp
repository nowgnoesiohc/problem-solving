#include <stdio.h>

int d[201] = {0};

int fibo(int n) {
  if (n == 1 || n == 2) return 1;
  if (d[n] != 0) return d[n];
  d[n] = (fibo(n - 1) + fibo(n - 2)) % 10009;
  return d[n];
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%d", fibo(n));
  return 0;
}
