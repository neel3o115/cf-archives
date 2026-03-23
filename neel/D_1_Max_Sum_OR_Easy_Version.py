import math

def fun(n):
    if n == 0:
        return 1

    if n & (n-1) == 0:
        return n-1

    
    y = math.ceil((math.log2(n)))
    return ((2**y)-1)^n


t = int(input())

for _ in range(t):
    l, r = map(int, input().split()) 
    a = [i for i in range(r+1)]
    b = [0] * (r+1)
    vis = [0] * (r+1)

    if r == 0: 
        print(0)
        print(r)
        continue

    for i in range(r,0,-1):
        x = fun(i)
        if (not vis[i]):
            b[i] = x
            b[x] = i
            vis[i] = 1
            vis[x] = 1

    if (vis[1] == 0):
        b[0] = 1
        b[1] = 0

    c = 0
    for i in range(r+1):
        c += a[i] | b[i]
    
    print(c)
    print(*b)
