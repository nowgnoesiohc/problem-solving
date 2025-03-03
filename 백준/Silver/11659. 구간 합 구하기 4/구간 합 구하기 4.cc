#include <stdio.h>

int main()
{
    int n, m , i, j, arr[100001]={0}, tmp;
    scanf("%d %d", &n, &m);
    for(int k=1;k<=n;k++){
        scanf("%d", &arr[k]);
        arr[k] += arr[k-1];
    }
    for(int k=1;k<=m;k++){
        scanf("%d %d", &i, &j);
        printf("%d\n", arr[j]-arr[i-1]);
    }
    return 0;
}