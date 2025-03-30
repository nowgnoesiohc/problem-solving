def DFS(v):
    vstd[v] = 1
    for nxt in grph[v]:
        if vstd[nxt] == 0:
            DFS(nxt)
            
n = int(input()) #컴퓨터 개수
v = int(input()) #연결선 개수

grph = [[] for _ in range(n+1)] #n+1 : for index 1
vstd = [0]*(n+1)

for i in range(v):
    a, b = map(int, input().split()) #a, b: 연결되어있음
    grph[a] += [b]
    grph[b] += [a]

DFS(1)
print(sum(vstd)-1)