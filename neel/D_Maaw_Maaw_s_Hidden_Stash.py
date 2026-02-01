PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    x = 0

    for i in range(n):
        if a[i] > x+1:
            print(x+1)
            return
        x += a[i]
    print(x+1)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()