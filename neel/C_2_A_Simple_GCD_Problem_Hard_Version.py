import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

prime = [1,2,3,5,7,11,13,17,19,23,29]
m = 11

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    dp = [[0 for i in range(m)] for j in range(n)]

    x = a[0]
    y = a[1]

    for i in range(m):
        z = math.gcd(x,y)
        if (math.gcd(z*prime[i],y) == z) and (z*prime[i] != x) and (z*prime[i] <= b[0]):
            dp[0][i] = 1

    for i in range(1,n-1):
        l = math.gcd(a[i-1],a[i])
        r = math.gcd(a[i],a[i+1])

        for j in range(m):
            if dp[i-1][j] != 0:
                x = l*prime[j]
                for k in range(m):
                    y = r*prime[k]

                    if (math.gcd(a[i],x) == l) and (math.gcd(a[i],y) == r) and (y != a[i]):
                        if (y > b[i]):
                            break

                        dp[i][k] = 1+dp[i-1][j]
    
    i = n-1
    l = math.gcd(a[i-1],a[i])
    r = math.gcd(a[i-1],a[i])

    for j in range(m):
        if dp[i-1][j] != 0:
            x = l*prime[j]
            for k in range(m):
                y = r*prime[k]
                if (math.gcd(a[i],x) == l) and (math.gcd(a[i],y) == r) and (y != a[i]):
                    if (y > b[i]):
                        break
                    dp[i][k] = 1+dp[i-1][j]

    print(max(dp[n-1]))
    # for i in dp:
    #     print(*i)
            
def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()