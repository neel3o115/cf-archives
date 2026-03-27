import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    g = a[0]

    for i in range(1,n):
        g = math.gcd(g,a[i])

    res = 0
    for i in range(n):
        if i == 0:
            nee = math.gcd(a[i],a[i+1])

        elif i == n-1:
            nee = math.gcd(a[i],a[i-1])

        else:
            r = math.gcd(a[i],a[i+1])
            l = math.gcd(a[i],a[i-1])

            nee = math.lcm(l,r)
        
        if a[i] != nee:
            res += 1
    
    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()