PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def check():

    return 0

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    p = [0]*(n+1)

    for i in range(1, n+1):
        p[i] = p[i-1]+a[i-1]


    tot = sum(a)
    x = tot/2

    print(*a)
    print(tot, x)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()