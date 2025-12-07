#include <stdio.h>

int min(int arr[], int n){
    int min = 100000;
    for(int i=0;i<n;i++){
        if(min>arr[i]) min = arr[i];
    }
    return min;
}
int main()
{
    int n, k, coin[100], dp[10001];
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i <= k; i++) dp[i] = 100000;
    dp[0] = 0;
    
    for(int i=0;i<n;i++) scanf("%d", &coin[i]);
    
    for(int i=0;i<n;i++){
        for(int j=coin[i];j<=k;j++){
            if(dp[j - coin[i]] != 100000) {
                dp[j] = (dp[j] < dp[j - coin[i]] + 1) ? dp[j] : dp[j - coin[i]] + 1;
            }
            // printf("coin : %d, cash : %d, dp : %d\n", coin[i], j, dp[j]);
        }
    }
    if (dp[k] == 100000) printf("-1\n");
    else printf("%d\n", dp[k]);
    return 0;
}
