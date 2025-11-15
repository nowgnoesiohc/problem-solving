#include <stdio.h>

int main() {
    int N, M;
    long long B;
    scanf("%d %d %lld", &N, &M, &B);

    int a[500][500];
    int minH = 256, maxH = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] < minH) minH = a[i][j];
            if (a[i][j] > maxH) maxH = a[i][j];
        }
    }

    long long bestTime = -1;
    int bestHeight = 0;

    // 높이 h를 minH ~ maxH까지만 봐도 됨
    for (int h = minH; h <= maxH; h++) {
        long long remove = 0; // 제거해서 얻는 블록 수
        long long add = 0;    // 쌓기 위해 필요한 블록 수

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int x = a[i][j];
                if (x > h) {
                    remove += (x - h);
                } else if (x < h) {
                    add += (h - x);
                }
            }
        }

        // 인벤토리 체크: 시작 B + 제거한 블록 - 쌓을 블록 >= 0 이어야 함
        if (B + remove < add) continue; // 불가능한 높이

        long long time = remove * 2 + add;

        if (bestTime == -1 || time < bestTime ||
            (time == bestTime && h > bestHeight)) {
            bestTime = time;
            bestHeight = h;
        }
    }

    printf("%lld %d\n", bestTime, bestHeight);
    return 0;
}
