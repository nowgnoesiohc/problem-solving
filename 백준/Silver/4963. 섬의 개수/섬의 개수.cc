#include <stdio.h>

int w, h;
int map[51][51];
int visited[51][51];

// 8방향 이동: 상, 하, 좌, 우, 대각선
int dx[8] = {-1,  1,  0,  0, -1, -1,  1,  1};
int dy[8] = { 0,  0, -1,  1, -1,  1, -1,  1};

void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
            if (map[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) break;

        // 지도 및 방문배열 초기화
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                scanf("%d", &map[i][j]);
                visited[i][j] = 0;
            }
        }

        int count = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j); // 새로운 섬 시작
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
