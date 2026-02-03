t = int(input())
N = 5000000

dp = [0]*(N+1)
spf = [0]*(N+1)

for i in range(2, N+1):
    if spf[i] == 0:
        for j in range(i,N+1,i):
            if spf[j] == 0:
                spf[j] = i


for i in range(2, N+1):
    dp[i] = dp[i//spf[i]] + 1

for i in range(1,N+1):
    dp[i] += dp[i-1]

for _ in range(t):
    a,b = map(int,input().split())
    print(dp[a]-dp[b])