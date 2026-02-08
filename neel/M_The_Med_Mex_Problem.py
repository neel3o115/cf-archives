PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def fac(n):
    if n == 0:
        return 1
    return n*fac(n-1);

def solve():
    n = int(input())
    
    x = fac(14)*11*fac(4)
    print(x%MOD2)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()