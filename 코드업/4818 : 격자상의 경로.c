#include <stdio.h>

void findCoor(int k, int m, int *x, int *y) {
  if (k % m == 0) {
    *x = m - 1;
    *y = k / m - 1;
  } else {
    *x = k - ((k / m) * m) - 1;
    *y = k / m;
  }
}

int cntCases(int n, int m) {
  int i, j;
  int jido[15][15] = {0};

  for (i = 0; i <= m; i++) jido[0][i] = 1;
  for (i = 0; i <= n; i++) jido[i][0] = 1;

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      jido[i][j] = jido[i - 1][j] + jido[i][j - 1];
      // printf("i:%d j:%d cnt:%d\n", i, j, jido[i][j]);
    }
  }
  return jido[n][m];
}

int main() {
  int n, m, k;
  int i, j;
  int x, y, new_x, new_y;
  int stt2k, k2end;
  int new1n, new1m, new2n, new2m;

  scanf("%d %d %d", &n, &m, &k);

  if (k == 0) k = n * m;

  // k's coordinates
  findCoor(k, m, &x, &y);
  // printf("k_x:%d k_y:%d\n", x, y);

  // number of cases from 1 to k
  stt2k = cntCases(y, x);
  // printf("%d\n", stt2k);

  // find the number of cases from k to n*m
  findCoor(n * m, m, &new_x, &new_y);
  // printf("new_x:%d new_y:%d\n", new_x, new_y);
  k2end = cntCases(new_y - y, new_x - x);
  // printf("%d", k2end);

  // result
  printf("%d", stt2k * k2end);

  return 0;
}