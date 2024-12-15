#include <stdio.h>
int isSelfNumber(int n){
    int cnt = 0, s;
    for(int i=1;i<=5000;i++){
        s = 0;
        for(int j=i;j>0;j/=10){
            s += j % 10;
        }
        if (i + s == n) cnt++;
        
    }
    return cnt;
}
int main()
{
    int a, b;
    int sum=0;
    scanf("%d %d", &a, &b);
    for(int i=a;i<=b;i++){
        if(isSelfNumber(i) == 0) sum += i;
    }
    
    printf("%d", sum);

    return 0;
}
