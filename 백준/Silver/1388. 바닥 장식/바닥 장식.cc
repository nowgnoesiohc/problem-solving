#include <stdio.h>
char map[51][51];
int N, M;
int visited[51][51];

void dfs(int x, int y, char type) {
    visited[x][y] = 1;

    if (type == '-') {
        // 오른쪽으로 같은 줄에서 계속 '-'
        int ny = y + 1;
        if (ny < M && !visited[x][ny] && map[x][ny] == '-') {
            dfs(x, ny, '-');
        }
    } else {
        // 아래로 같은 열에서 계속 '|'
        int nx = x + 1;
        if (nx < N && !visited[nx][y] && map[nx][y] == '|') {
            dfs(nx, y, '|');
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    // 바닥 장식 입력
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }

    int count = 0;

    // 전체 격자 순회
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                dfs(i, j, map[i][j]);
                count++;  // 새 판자 발견!
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
