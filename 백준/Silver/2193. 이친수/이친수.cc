#include <stdio.h>

int main()
{
    long long int dp[90]={0, 1, 1};
    int n;
    
    scanf("%d", &n);
    
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%lld", dp[n]);
    
    return 0;
}
