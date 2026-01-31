mod = 998244353
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
xy = [[] for i in range(m+1)]

P = 1
Q = 1

def bin_pow(a,p,m):
    res = 1

    while p>0:
        if (p&1):
            res = (res*a)%m
        p>>=1
        a=(a*a)%m
    return res

for i in range(n):
    l,r,p,q = map(int,input().split())
    xy[l].append([r,p,q])

    P = (P*(q-p))%mod
    Q = (Q*bin_pow(q,mod-2,mod))%mod

dp = [0]*(m+2)
dp[m+1] = 1

for i in range(m, 0, -1):
    tot = 0
    for end,x,y in xy[i]:
        nee = x*y%mod
        nee = nee*bin_pow(y*(y-x)%mod,mod-2,mod) % mod
        tot = (tot+nee * dp[end+1]) % mod

    dp[i] = tot

ans = dp[1]*P*Q%mod
print(ans)
