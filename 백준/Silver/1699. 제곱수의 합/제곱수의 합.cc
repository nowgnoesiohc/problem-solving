#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int N, dp[100001];
    scanf("%d", &N);

    // 초기화: 최악의 경우 1^2을 N번 더하는 경우
    for (int i = 1; i <= N; i++) dp[i] = i;

    // j*j 를 먼저 고정하고 i를 순회
    for (int j = 1; j * j <= N; j++) {
        for (int i = j * j; i <= N; i++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    printf("%d\n", dp[N]);
    return 0;
}
