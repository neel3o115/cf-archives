PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    
    rp = []
    for i in range(m):
        r, p = map(float, input().split())
        r = int(r)
        rp.append([r, p])
    rp.sort()

    x = 0
    
    for i in range(n-1, -1, -1):
        if a[i] == i+1:
            continue
        else:
            x = i+1
            break
        
    if x == 0:
        print(1)
        return 
    
    nee = []
    
    for i in range(m):
        if rp[i][0] >= x:
            nee.append(rp[i][1])
    
    k = len(nee)
    
    ans = 0
    crr = 1
    
    for i in range(0,k):
        temp = nee[i] * crr
        ans += temp
        crr *= (1-nee[i])
    
    print(f"{ans:.10f}")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()