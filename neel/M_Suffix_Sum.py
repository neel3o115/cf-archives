def rec(a, n, m):
    if n <= m:
        return 0
    return a[n] + rec(a, n-1, m)

n, m = map(int, input().split())
a = list(map(int, input().split()))

print(rec(a, n-1, n-m-1))
