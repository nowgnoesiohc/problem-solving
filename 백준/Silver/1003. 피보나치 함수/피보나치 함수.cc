#include <stdio.h>

int main()
{
    int t, n, dp[41] = {0, 1};
    
    for(int i = 2; i < 41; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        scanf("%d", &n);
		if (n == 0)
			printf("1 0\n");
		else
	        printf("%d %d\n", dp[n - 1], dp[n]);
    }

    return 0;
}