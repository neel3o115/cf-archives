PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = []
    dp = [0]*(1<<n)
    dp[0] = 1

    for i in range(n):
        r = list(map(int,input().split()))
        a.append(r)
    
    for mask in range(1,1<<n):
        m = mask.bit_count()

        for w in range(n):
            if a[m-1][w] and (mask&(1<<w)):
                dp[mask] = (dp[mask]+dp[mask & ~(1<<w)])%MOD1

    print(dp[(1<<n)-1])

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()