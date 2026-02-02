n,m = map(int,input().split())

a = []
b = []

for i in range(n):
    l = list(map(int,input().split()))
    a.append(l)

for i in range(n):
    l = list(map(int,input().split()))
    b.append(l)

c = [[0 for i in range(m)] for i in range(n)]

def rec(x,y,n,m):
    global a,b,c

    if x == n or y == m:
        return 0

    c[x][y] = a[x][y]+b[x][y]

    if (y == m-1):
        rec(x+1,0,n,m)
    else:
        rec(x,y+1,n,m)

rec(0,0,n,m)

for i in c:
    print(*i)