import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def check(x):
    return x&(x-1) == 0

def solve():
    n,m = map(int,input().split())

    g = math.gcd(n,m)

    if not check(m//g):
        print(-1)
        return

    n = n%m 

    g2 = math.gcd(n,m)

    nn = n//g2
    mm = m//g2

    print(m*bin(nn).count('1')-n)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()