import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = sorted([int(input()) for _ in range(n)])


def binary_search(array, target, start, end):
    
    while start<=end:
        mid = (start+end)//2
        
        if array[mid] == target:
            if end == mid:
                return mid
            end = mid
            
        elif array[mid] > target:
            end = mid-1
        else:
            start = mid+1
    return None

for i in range(m):
    target = int(input())
    result = binary_search(array, target, 0, n-1)
    if result == None:
        print(-1)
    else:
        print(result)

