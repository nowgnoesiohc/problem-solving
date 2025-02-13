h, w = map(int, input().split())
wo = list(map(int, input().split()))

world = [[0]*w for _ in range(h)]
cnt = 0

for j in range(w):
    a = 0
    for i in range(wo[j]):
        world[a][j] = 1
        a += 1

for i in range(h):
    side = False
    tmp_cnt = 0
    for j in range(1, w):
        
        if world[i][j] == 0:
            if world[i][j-1] == 1:
                side = True
            if side == True:
                tmp_cnt += 1
        if world[i][j] == 1:
            cnt += tmp_cnt
            tmp_cnt = 0
            side = False
        
print(cnt)