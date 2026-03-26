PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD = 676767677

def solve():
    n,m = map(int,input().split())
    b = list(map(int,input().split()))
    c = [0]*m
    a = [0]*n

    for i in range(n):
        c[b[i]] += 1
    
    for i in range(1,m):
        c[i] += c[i-1]

    for i in range(n):
        if b[i] == 0:
            a[i] = 1 

        else:
            x = -1
            if i == 0:
                r = b[i+1]
                x = r 

            elif i == n-1:
                l = b[i-1]
                x = l

            else:
                l = b[i-1]
                r = b[i+1]
                x = min(l,r)

            if x >= b[i]:
                a[i] = 0
            elif x == b[i]-1:
                a[i] = c[b[i]-1]
            else:
                a[i] = c[b[i]-1]-c[b[i]-2]

    res = 1

    for i in range(n):
        res = (res*a[i])%MOD

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()