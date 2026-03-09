n = int(input())
p = list(map(float,input().split()))

dp = [[0 for i in range(n+1)] for i in range(n+1)]
dp[0][0] = 1

for i in range(0,n+1):
    for j in range(0,n+1):
        if i == 0 and j == 0:
            continue
        dp[i][j] = dp[i-1][j]*(1-p[i-1]) + dp[i-1][j-1]*(p[i-1])

res = 0

for j in range(0,n+1):
    if j > n//2:
        res += dp[n][j]

print(res)