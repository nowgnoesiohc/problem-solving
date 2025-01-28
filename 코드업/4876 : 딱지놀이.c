#include <stdio.h>

int main() {
  int n, nn, m;
  int i, j;
  int a[5] = {0};
  int b[5] = {0};
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 1; j < 5; j++) {
      a[j] = 0;
      b[j] = 0;
    }
    scanf("%d", &nn);
    for (j = 0; j < nn; j++) {
      scanf("%d", &m);
      if (m == 4)
        a[4]++;
      else if (m == 3)
        a[3]++;
      else if (m == 2)
        a[2]++;
      else if (m == 1)
        a[1]++;
    }
    scanf("%d", &nn);
    for (j = 0; j < nn; j++) {
      scanf("%d", &m);
      if (m == 4)
        b[4]++;
      else if (m == 3)
        b[3]++;
      else if (m == 2)
        b[2]++;
      else if (m == 1)
        b[1]++;
    }
    if (a[4] > b[4])
      printf("A");
    else if (a[4] < b[4])
      printf("B");
    else if (a[3] > b[3])
      printf("A");
    else if (a[3] < b[3])
      printf("B");
    else if (a[2] > b[2])
      printf("A");
    else if (a[2] < b[2])
      printf("B");
    else if (a[1] > b[1])
      printf("A");
    else if (a[1] < b[1])
      printf("B");
    else
      printf("D");
    printf("\n");
  }

  return 0;
}