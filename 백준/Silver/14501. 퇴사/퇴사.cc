#include <stdio.h>
int max(int a, int b) {
    return a>b?a:b;
}
int main()
{
    int n;
    int t[16]={}, p[16]={}, dp[17]={0};
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d %d", &t[i], &p[i]);
    }
    
    for(int i=n;i>=1;i--){
        int end = i + t[i]-1;
        if(end <= n){
            dp[i] = max(dp[i+1], p[i]+dp[i+t[i]]);
        }
        else {
            dp[i] = dp[i+1];
        }
    }
    printf("%d", dp[1]);

    return 0;
}
