#include <stdio.h>

int s[3000];
int d[3000] = {0};

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int i, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
  }

  d[1] = s[1];
  d[2] = s[1] + s[2];
  d[3] = max(s[1] + s[3], s[2] + s[3]);

  for (i = 4; i <= n; i++)
    d[i] = max(d[i - 2] + s[i], d[i - 3] + s[i - 1] + s[i]);

  printf("%d", d[n]);

  return 0;
}