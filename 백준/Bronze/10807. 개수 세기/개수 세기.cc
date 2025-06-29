#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, v, count = 0;
    scanf("%d", &n);

    // 동적 메모리 할당
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 값 입력받기
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // 또는 *(arr + i)
    }

    scanf("%d", &v);

    // v가 몇 번 나오는지 세기
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == v) {
            count++;
        }
    }

    printf("%d\n", count);

    // 메모리 해제
    free(arr);
    return 0;
}
