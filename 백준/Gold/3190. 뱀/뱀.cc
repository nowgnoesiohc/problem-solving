#include <stdio.h>

#define MAX_N 100
#define MAX_L 100
#define MAX_BODY (MAX_N * MAX_N)

int N, K, L;
int board[MAX_N + 1][MAX_N + 1]; // 0:빈칸, 1:사과, 2:뱀

// 방향: 0:오른쪽, 1:아래, 2:왼쪽, 3:위
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int turnTime[MAX_L];
char turnDir[MAX_L];

// 뱀 몸통을 저장할 큐 (꼬리 -> 머리)
int snakeR[MAX_BODY];
int snakeC[MAX_BODY];
int front = 0, back = 0; // [front, back) 구간 사용

int main(void) {
    scanf("%d", &N);
    scanf("%d", &K);

    // 사과 위치 입력
    for (int i = 0; i < K; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 1; // 사과
    }

    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &turnTime[i], &turnDir[i]);
    }

    // 초기 상태 설정
    int time = 0;
    int dir = 0; // 처음 방향: 오른쪽
    int headR = 1, headC = 1;

    // 뱀 시작 위치
    board[1][1] = 2;
    snakeR[back] = 1;
    snakeC[back] = 1;
    back++;

    int turnIdx = 0;

    while (1) {
        time++;

        // 1. 머리를 다음 칸으로 이동
        int nR = headR + dr[dir];
        int nC = headC + dc[dir];

        // 2. 벽이나 자기 몸과 부딪히는지 확인
        if (nR < 1 || nR > N || nC < 1 || nC > N) {
            // 벽
            printf("%d\n", time);
            break;
        }
        if (board[nR][nC] == 2) {
            // 자기 몸
            printf("%d\n", time);
            break;
        }

        // 3. 사과 여부 확인
        if (board[nR][nC] == 1) {
            // 사과가 있으면: 사과 먹고 꼬리는 그대로 (길이 +1)
            board[nR][nC] = 2;
            // 머리 위치 큐에 추가
            snakeR[back] = nR;
            snakeC[back] = nC;
            back++;
        } else {
            // 사과가 없으면: 머리 늘리고 꼬리 한 칸 줄이기
            // 머리 위치 표시
            board[nR][nC] = 2;
            snakeR[back] = nR;
            snakeC[back] = nC;
            back++;

            // 꼬리 제거
            int tailR = snakeR[front];
            int tailC = snakeC[front];
            board[tailR][tailC] = 0; // 빈칸으로
            front++;
        }

        // 머리 좌표 갱신
        headR = nR;
        headC = nC;

        // 4. 이 시간이 끝난 뒤 방향 전환 체크
        if (turnIdx < L && time == turnTime[turnIdx]) {
            if (turnDir[turnIdx] == 'L') {
                dir = (dir + 3) % 4; // 왼쪽(반시계)
            } else if (turnDir[turnIdx] == 'D') {
                dir = (dir + 1) % 4; // 오른쪽(시계)
            }
            turnIdx++;
        }
    }

    return 0;
}
