n=int(input())
x=list(map(int,input().split()))

left, right, ans=0, n-1, 0    
while left+1 < right:
  ans=max(ans,(right-left-1)*min(x[left],x[right]))   
  if x[left]<x[right]:    
    left+=1
  else: 
    right-=1
      
print(ans)