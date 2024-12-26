#include <stdio.h>

void collatz(int n) {
    printf("%d\n", n);
    if(n<=1) return;
    if(n%2==1) collatz(3*n+1);
    else if(n%2==0) collatz(n/2);
}

int main() {
    int n;
    scanf("%d", &n);
    collatz(n);
    
    return 0;
}