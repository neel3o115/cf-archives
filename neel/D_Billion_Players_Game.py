PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, l, r = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    ps = [0] * (n + 1)
    for i in range(n):
        ps[i+1] = ps[i] + a[i]

    med = a[n//2]

    if med < l:
        x = l
    elif med > r:
        x = r
    else:
        x = med

    lo, hi = 0, n
    while lo < hi:
        mid = (lo+hi)//2
        if a[mid] < x:
            lo = mid+1
        else:
            hi = mid
    idx = lo

    ls = x * idx - ps[idx]
    rs = (ps[n] - ps[idx]) - x * (n - idx)

    print(ls + rs)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()
