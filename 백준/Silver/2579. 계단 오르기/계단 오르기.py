n=int(input())
s=[int(input()) for _ in range(n)] #stairs

d=[0]*(n) # dp

if len(s)<=2: # 계단이 2개 이하일 경우
    print(sum(s))

else: # 계단이 3개 이상일 경우
    d[0]=s[0] # 첫째 계단
    d[1]=s[0]+s[1] # 둘째 계단
    for i in range(2,n): # 3번째 계단부터는 점화식 이용 가능
        d[i]=max(d[i-3]+s[i-1]+s[i], d[i-2]+s[i])
    print(d[-1])