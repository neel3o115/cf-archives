def rec(a,n):
    if n < 0:
        return 0

    return a[n]+rec(a,n-1)

n = int(input())
a = list(map(int,input().split()))

print(rec(a,n-1))