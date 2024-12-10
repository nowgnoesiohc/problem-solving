#참고 https://tmdrl5779.tistory.com/138
n = int(input())
cal = [0] * 366

for i in range(n):
    start, end = map(int, input().split())
    
    for j in range(start, end+1):
        cal[j] += 1
        
garo = 0
sero = 0
res = 0

for i in range(366):
    if cal[i] == 0:
        res += garo * sero
        garo = 0
        sero = 0
    else:
        garo += 1
        sero = max(sero, cal[i])
res += garo * sero        
print(res)
    