#include <stdio.h>

int main() {
  char name[50][10];
  int n, score[50], score_s[50], tmp;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d", name[i], &score[i]);
    score_s[i] = score[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (score_s[i] < score_s[j]) {
        tmp = score_s[i];
        score_s[i] = score_s[j];
        score_s[j] = tmp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (score_s[2] == score[i]) printf("%s", name[i]);
  }
}