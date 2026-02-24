import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def gcd(a):
    g = a[0]

    for i in range(1,len(a)):
        g = math.gcd(g,a[i])
    
    return g

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    ps = [0]*(n+1)

    for i in range(n):
        ps[i+1] = ps[i]+a[i]

    res = gcd(a)
    for i in range(1,n):
        a = ps[i]
        b = s-a

        res = max(res,math.gcd(a,b))    

    print(res)    

def main():
    t = 1
    t = int(input())            
    for _ in range(t):
        solve()

main()