s = input()
t = input()

n = len(s)
m = len(t)

dp = [[0 for i in range(m+1)] for i in range(n+1)]

for i in range(1,n+1):
    for j in range(1,m+1):
        if s[i-1] == t[j-1]:
            dp[i][j] = 1+dp[i-1][j-1]
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])

lcs = ""
i,j = n,m

while i>0 and j>0:
    if s[i-1] == t[j-1]:
        lcs += s[i-1]
        i -= 1
        j -= 1
    elif dp[i-1][j] > dp[i][j-1]:
        i -= 1
    else:
        j -= 1

print(lcs[::-1])