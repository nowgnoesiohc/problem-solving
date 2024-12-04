#include <stdio.h>

int main()
{
    int n, a, b, c, d[101], dmax=0, tmp, ttmp, maxx=0;
    
    // 토핑 종류 수
    scanf("%d", &n);

    // A는 도우의 가격, B는 토핑의 가격을 나타낸다.
    scanf("%d %d", &a, &b);

    // 도우 칼로리
    scanf("%d", &c);

    // 토핑 칼로리
    for(int i=1;i<=n;i++){
        scanf("%d", &d[i]);
    }
    
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(d[i]<d[j]){
                tmp = d[i];
                d[i] = d[j];
                d[j] = tmp;
            }
        }
    }
    d[0] = 0;
    
    // for(int i=0;i<=n;i++) printf("\n====%d====", d[i]);
    // printf("\n\n");
    
    for(int i=0;i<=n;i++){
        tmp=0;
        for(int j=0;j<=i;j++){
            tmp += d[j];
        }
        ttmp = (tmp+c)/(i*b+a);
        // printf("\n%d+%d/%d\n", tmp, c, (i*b+a));
        // printf("%d %d %d\n\n", tmp, ttmp, maxx);
        if(ttmp>maxx) maxx=ttmp;
    }
    // 1달러 당 열량이 최대가 되는 피자의 1달러 당 열량
    printf("%d", maxx);
    return 0;
}