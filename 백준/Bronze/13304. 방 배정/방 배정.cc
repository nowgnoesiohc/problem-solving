#include <stdio.h>

int main()
{
    int a[7]={0}, b[7]={0};
    int i, j;
    int n, m, s, g, tt=0, atmp, btmp;
    
    scanf("%d %d", &n, &m);
    
    for(i=0;i<n;i++){
        scanf("%d %d", &s, &g);
        if(s==0) a[g]++;
        if(s==1) b[g]++;
    }
    
    for(i=1;i<=6;i+=2){
        atmp = a[i]+a[i+1];
        btmp = b[i]+b[i+1];
        
        if(i==1) {
            if((atmp+btmp)%m==0) tt += (atmp+btmp)/m;
            else tt += (atmp+btmp)/m + 1;
        }
        else{
            if(atmp%m==0) tt += atmp/m;
            else tt += atmp/m + 1;
            
            if(btmp%m==0) tt += btmp/m;
            else tt += btmp/m + 1;
        }
    }
    printf("%d", tt);
    return 0;
}