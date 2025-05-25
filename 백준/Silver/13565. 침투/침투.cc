#include <stdio.h>

#define MAX 1000

int M, N;
char grid[MAX][MAX + 1];  // 각 행은 문자열로 받아들이므로 +1
int visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};  // 상하좌우
int dy[] = {0, 0, -1, 1};
int success = 0; // 전류가 아래쪽까지 도달했는지 여부

void dfs(int x, int y) {
    if (x == M - 1) {
        success = 1; // 아래쪽에 도달
        return;
    }

    visited[x][y] = 1;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
            if (!visited[nx][ny] && grid[nx][ny] == '0') {
                dfs(nx, ny);
                if (success) return;  // 이미 성공했으면 더 탐색할 필요 없음
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        scanf("%s", grid[i]);  // 문자열로 입력 받음
    }

    // 바깥쪽(첫 번째 행)의 모든 0에서 DFS 시도
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == '0' && !visited[0][j]) {
            dfs(0, j);
            if (success) break;
        }
    }

    if (success)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
