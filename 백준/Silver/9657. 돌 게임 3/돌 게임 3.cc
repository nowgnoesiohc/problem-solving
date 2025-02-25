#include <stdio.h>

int main()
{
    int n, dp[1000]={-1, 0, 1, 0, 0, 0};
    scanf("%d", &n);
    
    for(int i=6;i<=n;i++){
        if(dp[i-1]==0 && dp[i-3]==0 && dp[i-4]==0) dp[i]=1;
        else dp[i]=0;
    }
    if(dp[n]==0) printf("SK");
    else printf("CY");
    
    return 0;
}
