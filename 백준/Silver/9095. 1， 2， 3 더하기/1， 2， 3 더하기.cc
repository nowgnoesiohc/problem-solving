#include <stdio.h>

int d[11]={0, 1, 2, 4};

int main(){
    int N, n, i;
    
    for(i=4;i<=11;i++) d[i] = d[i-3]+d[i-2]+d[i-1];
    
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }    
    return 0;
}