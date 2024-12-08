#include <stdio.h>
int calRemainApple(int std, int apl) {
    for(int i=apl;;i--){
        if(i%std==0) return (apl-i);
    }
}

int main()
{
    int n, std, apl, tt=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &std, &apl);
        tt += calRemainApple(std, apl);
    }
    printf("%d", tt);
    return 0;
}
