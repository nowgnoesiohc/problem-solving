#include <stdio.h>
int main()
{
    long long int d[1000001] = {0, 1, 2, 4};
    int T, n;

    for(int i=4;i<=1000000;i++){
        d[i] = (d[i-3] + d[i-2] + d[i-1]) % 1000000009;
    }
    
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d", &n);
        printf("%lld\n", d[n]);
    }

    return 0;
}