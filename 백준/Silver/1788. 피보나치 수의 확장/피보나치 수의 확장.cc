#include <stdio.h>

int main()
{
    int n, dp[1000001]={0, 1};
    int INF = 1000000000;
    scanf("%d", &n);
    int nn = n < 0 ? -n : n;

    for(int i=2;i<=nn;i++){
        dp[i] = (dp[i-1] + dp[i-2])%INF;
    }
    if(n < 0 && nn%2==0) printf("-1\n");
    else if(n==0) printf("0\n");
    else printf("1\n");
    printf("%d", dp[nn]);
    return 0;
}
