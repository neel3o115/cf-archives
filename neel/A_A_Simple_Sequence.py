PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    p = [0]*n

    for i in range(n):
        p[i] = n-i
    
    print(*p)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()