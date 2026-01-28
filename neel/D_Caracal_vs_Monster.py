res = 0
dp = {}

def fun(n):
    if n == 1:
        return 1
    
    if n in dp:
        return dp[n]
    
    dp[n] = 1+2*(fun(n//2))
    return dp[n]

n = int(input())
print(fun(n))