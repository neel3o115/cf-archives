n = int(input())
a = []

for i in range(n):
    a.append(int(input()))

x = sum(a)

c = [[0 for _ in range(x+1)] for _ in range(x+1)]

for i in range(x+1):
    c[i][0] = 1      
    c[i][i] = 1        

for i in range(1, x+1):
    for j in range(1, i):
        c[i][j] = c[i-1][j-1] + c[i-1][j]

ans = 1

for i in range(n-1,0,-1):
    ans = (ans*c[x-1][a[i]-1])%1000000007
    x -= a[i]

print(ans%1000000007)