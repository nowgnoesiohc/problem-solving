#include <stdio.h>
int main()
{
    int a,b,c,d,n;
    int arr[100001]={0};
    scanf("%d %d",&a, &b);
    for(int i=1;i<=a;i++){
        scanf("%d",&n);
        arr[i]=arr[i-1]+n;
    }
    for(int i=0;i<b;i++){
        scanf("%d %d",&c, &d);
        printf("%d\n",arr[d]-arr[c-1]);
    }
    return 0;
}