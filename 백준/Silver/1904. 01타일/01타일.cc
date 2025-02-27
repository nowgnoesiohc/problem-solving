#include <stdio.h>

int main()
{
    int n, dp[1000000]={0, 1, 2, 3, 5};
    scanf("%d", &n);
    
    for(int i=5;i<=n;i++){
        dp[i] = (dp[i-2]+dp[i-1]) % 15746;
    }
    
    printf("%d", dp[n]);
    return 0;
}
