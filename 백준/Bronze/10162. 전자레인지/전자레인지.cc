#include <stdio.h>
int main(){
    int t, tt[3], cnt[3];
    scanf("%d", &t);
    tt[0]=5*60; tt[1]=60; tt[2]=10;
    
    for(int i=0;i<3;i++){
        cnt[i] = t/tt[i];
        t = t%tt[i];
    }
    if(t!=0) printf("-1");
    else printf("%d %d %d", cnt[0], cnt[1], cnt[2]);
    return 0;
}