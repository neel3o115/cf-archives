PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,k = map(int,input().split())
    x,a,b,c = map(int,input().split())

    v = [0]*n 
    v[0] = x
    
    for i in range(1,n):
        v[i] = (a*v[i-1]+b)%c
    
    pr = [0]*n
    sf = [0]*n

    for i in range(0,n,k):
        pr[i] = v[i]
    
    for i in range(k-1,n,k):
        sf[i] = v[i]
    sf[-1] = v[-1]

    for i in range(0,n):
        if i%k != 0:
            pr[i] = pr[i-1]|v[i]

    for i in range(n-2,-1,-1):
        if i%k != k-1:
            sf[i] = sf[i+1]|v[i]

    res = 0
    for i in range(k-1,n):
        if i%k == k-1:
            res ^= pr[i]
        else:
            res ^= pr[i]|sf[i-k+1]

    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()
