#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);

    int orig = N;
    int cur = N;
    int count = 0;

    do {
        int tens = cur / 10;        // 십의 자리
        int ones = cur % 10;        // 일의 자리
        int sum = tens + ones;      // 합
        cur = (ones * 10) + (sum % 10); // 새 수: (현재 일의 자리)(합의 일의 자리)
        count++;
    } while (cur != orig);

    printf("%d\n", count);
    return 0;
}
