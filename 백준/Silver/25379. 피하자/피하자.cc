#include <stdio.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    long long cntOdd = 0;   // 지금까지 나온 홀수 개수
    long long cntEven = 0;  // 지금까지 나온 짝수 개수
    long long swaps_even_first = 0; // [짝수들 -> 홀수들] 패턴
    long long swaps_odd_first  = 0; // [홀수들 -> 짝수들] 패턴

    for (int i = 0; i < N; i++) {
        long long x;
        scanf("%lld", &x);

        if (x % 2 == 0) { // 짝수 (0도 포함)
            // [짝수 -> 홀수] 패턴에서는
            // 이 짝수 앞에 있는 홀수들만큼 스왑 필요
            swaps_even_first += cntOdd;

            // [홀수 -> 짝수] 패턴에서는
            // 짝수는 나중 블록이므로 지금은 패널티 없음
            cntEven++;
        } else { // 홀수
            // [홀수 -> 짝수] 패턴에서는
            // 이 홀수 앞에 있는 짝수들만큼 스왑 필요
            swaps_odd_first += cntEven;

            // [짝수 -> 홀수] 패턴에서는
            // 홀수는 나중 블록이므로 지금은 패널티 없음
            cntOdd++;
        }
    }

    // 두 패턴 중 더 작은 스왑 횟수
    long long ans = (swaps_even_first < swaps_odd_first)
                  ? swaps_even_first
                  : swaps_odd_first;

    printf("%lld\n", ans);
    return 0;
}
