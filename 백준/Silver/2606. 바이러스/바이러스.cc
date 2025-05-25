#include <stdio.h>

#define MAX 101

int graph[MAX][MAX];     // 인접 행렬 방식
int visited[MAX];        // 방문 체크
int N, M;                // N: 컴퓨터 수, M: 연결 수
int count = 0;           // 감염된 컴퓨터 수

void dfs(int node) {
    visited[node] = 1;

    for (int i = 1; i <= N; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            count++;          // 감염된 컴퓨터 수 증가
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);     // 컴퓨터 수
    scanf("%d", &M);     // 연결 수

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1; // 양방향 연결
    }

    dfs(1); // 1번 컴퓨터부터 시작

    printf("%d\n", count); // 1번 제외한 감염된 수

    return 0;
}
