n,s = map(int,input().split())
a = list(map(int,input().split()))

i = 0
nee = 0
ans = 0

for j in range(n):
    nee += a[j]
    
    while nee > s:
        nee -= a[i]
        i += 1
    
    ans = max(ans,j-i+1)

print(ans)