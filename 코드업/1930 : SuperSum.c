#include <stdio.h>
int superSum(int k, int n) {
  // SuperSum(k,n) = SuperSum(k−1,1) + SuperSum(k−1,2) + ... + SuperSum(k−1,n)
  int tt = 0;
  if (k == 0) return n;
  for (int i = 1; i <= n; i++) tt += superSum(k - 1, i);
  return tt;
}

int main() {
  int k, n;
  while (scanf("%d %d", &k, &n) != EOF) {
    printf("%d\n", superSum(k, n));
  }

  return 0;
}