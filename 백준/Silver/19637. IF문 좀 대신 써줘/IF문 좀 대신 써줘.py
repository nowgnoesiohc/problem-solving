import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = [input().split() for _ in range(n)]


def binary_search(array, target, start, end):
    
    result = 0
    while start<=end:
        mid = (start+end)//2
        if int(array[mid][1]) >= target:
            end = mid - 1
            result = mid
        else:
            start = mid+1
    return result

for i in range(m):
    target = int(input())
    result = binary_search(array, target, 0, n-1)
    print(array[result][0])