import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    l, r = map(int, input().split())
    if l == r:
        print(l)
        return

    res = (r-l-1)+r+math.gcd(l,r)
    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()