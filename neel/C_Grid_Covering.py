import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,m,a,b = map(int,input().split())

    if math.gcd(n,a) != 1: 
        print("NO")
        return

    if math.gcd(m,b) != 1:
        print("NO")
        return
    
    if math.gcd(n,m) > 2:
        print("NO")
        return

    print("YES")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()