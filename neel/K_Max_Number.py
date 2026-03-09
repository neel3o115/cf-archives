def rec(a,n,m=-float('inf')):
    if n < 0:
        return m

    if a[n]>m: 
        return rec(a,n-1,a[n])
    return rec(a,n-1,m)

n = int(input())
a = list(map(int,input().split()))

print(rec(a,n-1))