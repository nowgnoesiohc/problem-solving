#include <stdio.h>
int min(int a, int b) {return a < b ? a : b;}

int main()
{
    int N, dp[3][1001], cost[3][1001];
    scanf("%d", &N);
    for(int i=1;i<=N;i++) scanf("%d %d %d", &cost[0][i], &cost[1][i], &cost[2][i]);
    
    dp[0][1] = cost[0][1];
    dp[1][1] = cost[1][1];
    dp[2][1] = cost[2][1];
    
    for(int i=2;i<=N;i++){
        dp[0][i] = cost[0][i] + min(dp[1][i-1], dp[2][i-1]);
        dp[1][i] = cost[1][i] + min(dp[0][i-1], dp[2][i-1]);
        dp[2][i] = cost[2][i] + min(dp[0][i-1], dp[1][i-1]);
    }
    
    int res = 1000000;
    for(int i=0;i<3;i++){
        res = res < dp[i][N] ? res : dp[i][N];
    }
    printf("%d", res);
    
    return 0;
}