import math
n = int(input())

a = [0]*(n+1)
k = math.ceil(math.sqrt(n))+1

for i in range(2, k+1):
    for j in range(i*i, n+1, i):
        a[j] += 2

ans = 1

for i in range(2,n+1):
    ans += i*(a[i]+2)

print(a)
print(ans)