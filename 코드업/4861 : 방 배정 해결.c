#include <stdio.h>

int main()
{
    int a[7]={0}, b[7]={0};
    int i, j;
    int n, m, s, g, tt=0;
    
    scanf("%d %d", &n, &m);
    
    for(i=0;i<n;i++){
        scanf("%d %d", &s, &g);
        if(s==0) a[g]++;
        if(s==1) b[g]++;
    }
    
    for(i=1;i<=6;i++){
        if(a[i]%m==0) tt += a[i]/m;
        else tt += a[i]/m + 1;
        
        if(b[i]%m==0) tt += b[i]/m;
        else tt += b[i]/m + 1;
    }
    
    printf("%d", tt);
    return 0;
}
