PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

prime = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67]

def fac(n):
    res = 0
    i = 0

    while n != 1:
        if n%prime[i] == 0:
            n //= prime[i]
            res ^= 1<<i
        else:
            i += 1
    
    return res

def solve():
    n = int(input())
    a = list(map(int,input().split()))
    
    nee = {}

    for i in range(n):
        nee[fac(a[i])] = nee.get(fac(a[i]),0)+1

    x = [0]
    y = [nee.get(0,0)]

    for i in nee:
        if i != 0:
            x.append(i)
            y.append(nee[i])

    m = len(x)

    dp = [[-1 for i in range(1<<20)] for j in range(50)]

    def rec(idx,value):
        if dp[idx][value] != -1:
            return dp[idx][value]
        
        if idx == m:
            return 1 if value == 0 else 0
        
        eve = pow(2,y[idx]-1,MOD1)
        odd = eve

        dp[idx][value] = (eve*rec(idx+1,value^x[idx])+odd*rec(idx+1,value))%MOD1
        return dp[idx][value]
    
    print((rec(0,0)-1)%MOD1)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()