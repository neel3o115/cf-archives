PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    pr = a[::]
    sf = a[::]

    for i in range(1, n):
        pr[i] = pr[i-1]&pr[i]

    for i in range(n-2,-1,-1):
        sf[i] = sf[i+1]&sf[i]
    
    res = 0

    for i in range(n):
        if i == 0:
            res = max(res, abs(sf[i+1]-a[i]))
        elif i == n-1:
            res = max(res, abs(pr[n-2]-a[i]))
        else:
            res = max(res, abs((pr[i-1]&sf[i+1])-a[i]))

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()