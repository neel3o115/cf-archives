dp = {}

def lnn(n):
    if n <= 1:
        return 1
    
    if n in dp:
        return dp[n]
    
    dp[n] = 2*lnn(n//2)+1
    return dp[n]

def rec(n,k):
    if n == 1:
        return 1
    
    nee = lnn(n)//2+1
    
    if k == nee:
        return n%2

    if k > nee:
        return rec(n//2,k-(nee))
    
    if k < nee:
        return rec(n//2,k)

n,l,r = map(int,input().split())
cnt = 0

for i in range(l,r+1):
    if rec(n,i):
        cnt += 1

print(cnt)