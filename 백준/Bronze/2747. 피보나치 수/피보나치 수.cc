// 백준 2747
#include<stdio.h>
 
int main(){
    // DP 테이블 초기화
    long long int d[101] = {0};
    int n;
    scanf("%d", &n);
    
    // 첫 번째 및 두 번째 피보나치 수 초기화
    d[1] = 1;
    d[2] = 1;
    
    // 보텀업 다이나믹 프로그래밍 방식으로 피보나치 수열 계산
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    
    // 결과 출력
    printf("%lld\n", d[n]);
    return 0;
}