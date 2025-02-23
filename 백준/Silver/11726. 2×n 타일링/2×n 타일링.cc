#include <stdio.h>
int main(){
    int dp[1000]={0, 1, 2}, n;
    
    scanf("%d", &n);
    
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }
    printf("%d", dp[n]);
    return 0;
}