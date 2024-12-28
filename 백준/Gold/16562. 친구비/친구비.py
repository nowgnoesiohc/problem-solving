def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if A[a] < A[b]:  # 친구비 적으면 부모
        parent[b] = a
    else:
        parent[a] = b

n, m, k = map(int, input().split())  # 노드 수, 간선(유니온 연산)의 수
A = list(map(int, input().split()))
A.insert(0, 0)
parent = [0] * (n + 1)

for i in range(1, n + 1):
    parent[i] = i

for i in range(m):
    v, w = map(int, input().split())
    union_parent(parent, v, w)

#print(parent)

for i in range(1, n+1):
    find_parent(parent, i)

#print(parent)

parent_list = []  # 부모 리스트
# print('부모테이블: ', end='')
for i in range(1, n + 1):
    if parent[i] not in parent_list:
        parent_list.append(parent[i])
    # print(parent[i], end='')

t = 0
# print()
# print(parent_list)

for i in parent_list:
    t += A[i]

if t > k:
    print('Oh no')
else:
    print(t)