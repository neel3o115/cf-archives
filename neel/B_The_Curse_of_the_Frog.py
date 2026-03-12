PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,x = map(int, input().split())
    a = []
    b = []
    c = []
    g = []
    d = []

    for i in range(n):
        aa, bb, cc = map(int,input().split())
        a.append(aa)
        b.append(bb)
        c.append(cc)
        g.append(aa*(bb-1))
        d.append(aa*bb-cc)
    
    for i in range(n):
        x -= g[i]

    if x <= 0:
        print(0)
        return
    
    if (max(d) <= 0):
        print(-1)
        return
    
    D = max(d)
    print((x+D-1)//D)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()
