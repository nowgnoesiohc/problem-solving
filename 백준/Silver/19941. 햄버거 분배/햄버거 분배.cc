#include <stdio.h>
#include <string.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    char s[20001];
    scanf("%s", s);

    int cnt = 0;

    // 사람을 기준으로 왼쪽 -> 오른쪽 스캔
    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {  // 사람 발견
            int start = i - K;
            int end   = i + K;
            if (start < 0) start = 0;
            if (end >= N) end = N - 1;

            // 왼쪽에서 오른쪽으로, 아직 안 먹힌 햄버거 찾기
            for (int j = start; j <= end; j++) {
                if (s[j] == 'H') {
                    cnt++;
                    s[j] = 'X';  // 먹힌 햄버거 표시
                    break;       // 이 사람은 먹었으니 다음 사람으로
                }
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
