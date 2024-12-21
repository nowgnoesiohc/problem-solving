#include <stdio.h>

int main()  
{
    int n, k, mx=-100000, i, j, sum, tmp[1000000]={0};
    scanf("%d %d", &n, &k);
    for(i=0;i<n;i++){
        scanf("%d", &tmp[i]);
    }
    for(i=0;i<=n-k;i++){
        sum=0;
        for(j=0;j<k;j++){
            sum += tmp[i+j];
        }
        // printf(" sum: %d\n", sum);
        if(mx<sum) mx=sum;
    }
    printf("%d", mx);
    
    return 0;
}
