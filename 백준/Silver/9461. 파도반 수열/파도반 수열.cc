#include <stdio.h>

int main()
{
    int t, n;
    long long int dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    
    for(int i = 11; i <= 100; i++)
        dp[i] = dp[i - 1] + dp[i - 5];
        
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
		printf("%lld\n", dp[n]);
    }

    return 0;
}