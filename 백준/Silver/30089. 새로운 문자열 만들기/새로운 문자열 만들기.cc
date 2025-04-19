#include <stdio.h>
#include <string.h>

#define MAX_LEN 21

// 문자열 뒤집기 함수
void reverse(char* src, char* dest) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - i - 1];
    }
    dest[len] = '\0';
}

int main() {
    int T;
    scanf("%d", &T);

    char S[MAX_LEN], R[MAX_LEN], X[MAX_LEN * 2];

    while (T--) {
        scanf("%s", S);
        int len = strlen(S);
        reverse(S, R);  // R = S 뒤집기

        for (int i = 0; i <= len; i++) {
            if (strncmp(S + i, R, len - i) == 0) {
                // S[i:] == R[:len-i] 라면
                strncpy(X, S, len);           // S 복사
                strcpy(X + len, R + (len - i)); // 겹치지 않는 부분만 이어붙이기
                printf("%s\n", X);
                break;
            }
        }
    }

    return 0;
}
