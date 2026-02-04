def rec(a,k):
    if k == 1:
        return a[k-1]
    
    pre = rec(a,k-1)
    return (pre*(k-1) + a[k-1]) / k

n = int(input())
a = list(map(int,input().split()))

print(rec(a,n))