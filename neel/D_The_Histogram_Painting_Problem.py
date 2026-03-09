import sys
sys.setrecursionlimit(10000)

def rec(a):
    if len(a) == 0:
        return 0
    
    n = len(a)
    m = min(a)

    if m > n:
        return n

    res = m

    for i in range(n):
        a[i] -= m
    
    st = 0

    for i in range(n):
        if a[i] == 0:
            res += rec(a[st:i])
            st = i+1
    
    res += rec(a[st:n])

    return res

n = int(input())
a = list(map(int,input().split()))
print(rec(a))