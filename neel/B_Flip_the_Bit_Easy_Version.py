PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    p = list(map(int,input().split()))

    sp = p[0]-1
    x = a[sp]
    
    l = 0
    flip = 0
    
    for i in range(sp):
        if (a[i]^flip) != x:
            l += 1
            flip ^= 1
    
    r = 0
    flip = 0
    
    for i in range(n-1,sp,-1):
        if (a[i]^flip) != x:
            r += 1
            flip ^= 1
    
    ans = max(l,r)
    
    if ans%2!=0:
        ans += 1
    
    print(ans)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()