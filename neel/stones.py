n,k = map(int,input().split())
a = list(map(int,input().split()))
a.sort()

dp = [0 for i in range(k+1)]

for i in range(1,k+1):
    for j in range(n):
        if i-a[j] >= 0:
            if dp[i-a[j]] == 0:
                dp[i] = dp[i] or 1
            else:
                dp[i] = dp[i] or 0

if dp[k] == 0:
    print('Second')
else:
    print('First')