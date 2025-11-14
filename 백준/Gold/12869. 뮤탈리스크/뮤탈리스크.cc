#include <stdio.h>

#define INF 0x3f3f3f3f
#define MAXH 60

int dp[MAXH+1][MAXH+1][MAXH+1];
int dmg[6][3] = {
    {9,3,1},{9,1,3},{3,9,1},
    {3,1,9},{1,9,3},{1,3,9}
};

int min(int a, int b){ return a < b ? a : b; }

int solve(int a, int b, int c){
    if (a < 0) a = 0;
    if (b < 0) b = 0;
    if (c < 0) c = 0;
    if (a == 0 && b == 0 && c == 0) return 0;

    int *memo = &dp[a][b][c];
    if (*memo) return *memo - 1; // 0이면 미계산, 저장은 +1로

    int best = INF;
    for (int i = 0; i < 6; ++i){
        int na = a - dmg[i][0];
        int nb = b - dmg[i][1];
        int nc = c - dmg[i][2];
        best = min(best, 1 + solve(na, nb, nc));
    }
    *memo = best + 1; // 0과 구분하려고 +1 보관
    return best;
}

int main(){
    int N;
    scanf("%d", &N);

    int a=0,b=0,c=0;
    if (N >= 1) scanf("%d", &a);
    if (N >= 2) scanf("%d", &b);
    if (N >= 3) scanf("%d", &c);

    // 순서 상관없이 풀어도 되지만, 약간의 가지치기를 위해 큰 순서로 정렬해도 좋음(선택)
    // 간단히 그대로 진행해도 통과합니다.

    printf("%d\n", solve(a,b,c));
    return 0;
}
