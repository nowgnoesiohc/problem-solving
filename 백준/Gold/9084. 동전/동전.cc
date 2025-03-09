#include <stdio.h>

int main()
{
    int t, coin[20], cash, n;
    scanf("%d", &t); // 테스트케이스 수
    for(int i=0;i<t;i++){
        int dp[10001]={0};
        
        scanf("%d", &n); // 동전의 가지 수
        for(int j=0;j<n;j++){
            scanf("%d", &coin[j]); // 동전의 각 금액
        }
        scanf("%d", &cash); // 동전으로 만들어야 할 금액
        
        dp[0] = 1;
        for(int co=0;co<n;co++){
            for(int ca=coin[co];ca<=cash;ca++){
                dp[ca] += dp[ca-coin[co]];
            }
        }
        printf("%d\n", dp[cash]);
    }
    return 0;
}
