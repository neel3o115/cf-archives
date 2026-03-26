PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = []

    for i in range(n):
        x, y = map(int, input().split())
        a.append(x//y)
    
    nee = max(a)

    for i in range(n):
        if (a[i] == nee):
            print(i+1)
            return

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()