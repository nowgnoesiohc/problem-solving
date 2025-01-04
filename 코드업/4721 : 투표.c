#include <stdio.h>

int main()
{
    int n, a[1001], b[1001], c[1001], i, j;
    int att=0, btt=0, ctt=0;
    int acnt[4]={0}, bcnt[4]={0}, ccnt[4]={0};
    int maxx, maxx_num;
    
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d %d %d", &a[i], &b[i], &c[i]);
        att += a[i];
        btt += b[i];
        ctt += c[i];
    }
    
    for(i=1;i<=3;i++){
        for(j=0;j<n;j++){
            if(i==a[j]) acnt[i]++;
            if(i==b[j]) bcnt[i]++;
            if(i==c[j]) ccnt[i]++;
        }
    }
    // printf("total : %d %d %d\n", att, btt, ctt);
    // printf("test_3 : %d %d %d\n", acnt[3], bcnt[3], ccnt[3]);
    if(att>btt && att>ctt) {maxx=att; maxx_num=1;}
    else if(btt>att && btt>ctt) {maxx=btt; maxx_num=2;}
    else if(ctt>att && ctt>btt) {maxx=ctt; maxx_num=3;}
    else{
        if(att>=btt && att>=ctt) {maxx=att; maxx_num=0;}
        else if(btt>=att && btt>=ctt) {maxx=btt; maxx_num=0;}
        else if(ctt>=att && ctt>=btt) {maxx=ctt; maxx_num=0;}
        for(i=3;i>1;i--){
            if(acnt[i]>bcnt[i] && acnt[i]>ccnt[i]) {maxx=att; maxx_num=1; break;}
            else if(bcnt[i]>acnt[i] && bcnt[i]>ccnt[i]) {maxx=btt; maxx_num=2; break;}
            else if(ccnt[i]>acnt[i] && ccnt[i]>bcnt[i]) {maxx=ctt; maxx_num=3; break;}
        }
    }
    printf("%d %d", maxx_num, maxx);

    return 0;
}