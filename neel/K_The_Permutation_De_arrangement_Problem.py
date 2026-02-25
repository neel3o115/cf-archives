n,k = map(int,input().split())

dp = [0] * (n+1)
dp[0] = 1
if n >= 1:
    dp[1] = 0

for i in range(2, n+1):
    dp[i] = (i - 1) * (dp[i-1] + dp[i-2])

 
c = [[0 for _ in range(n+1)] for _ in range(n+1)]
 
for i in range(n+1):
    c[i][0] = 1      
    c[i][i] = 1        
 
for i in range(1, n+1):
    for j in range(1, i):
        c[i][j] = c[i-1][j-1] + c[i-1][j]

res = 1

for i in range(1,n+1):
    res *= i

for i in range(n,k,-1):
    res -= dp[i]*c[n][n-i]

print(res)