#include <stdio.h>
int getGCD(int a, int b){
    if(a%b==0) return b;
    else return getGCD(b, a%b);
}

int main()
{
    int d1, d2, gcd, cnt=0;
    short int dot[2000][2000]={0};
    scanf("%d %d", &d1, &d2);

    for(int i=d1;i<=d2;i++){
        for(int j=1;j<i;j++){
            gcd = getGCD(i, j);
            if(dot[i/gcd][j/gcd] == 0) {
                dot[i/gcd][j/gcd] = 1;
                cnt++;
            }
        }
    }
   
    printf("%d", cnt+1);
    return 0;
}