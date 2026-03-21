n,s = map(int,input().split())
a = list(map(int,input().split()))

i = 0
nee = 0
ans = n

for j in range(n):
    nee += a[j]
    
    while nee >= s:
        nee -= a[i]
        i += 1

        ans = min(ans,j-(i-1)+1)

if ans == n and sum(a) < s:
    print(-1)
else:
    print(ans)