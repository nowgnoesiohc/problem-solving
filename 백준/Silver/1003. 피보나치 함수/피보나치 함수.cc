#include <stdio.h>
int main()
{
    int a,b,i;
    long long int arr[101]={1,1};
    scanf("%d",&a);
    for(i=2;i<=101;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    for(i=0;i<a;i++){
        scanf("%d",&b);
        if(b==0){
            printf("%d %d\n",1,0);
        }
        else if(b==1){
            printf("%d %d\n",0,1);
        }
        else{
            printf("%lld %lld\n",arr[b-2],arr[b-1]);
        }
    }
    return 0;
}