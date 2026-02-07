PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    p = [0]*(n+1)

    for i in range(1,n+1):
        p[i] = p[i-1]+a[i-1]
    
    l = 1
    r = n

    while (l <= r):
        x = p[r]-p[l-1]
        y = (l+r)*(r-l+1)
        d = y-x

        xl = p[r]-p[l]
        yl = (l+1+r)*(r-(l+1)+1)
        dl = yl - xl

        xr = p[r-1]-p[l-1]
        yr = (l+r-1)*(r-1-l+1)
        dr = yr - xr 

        if dl>d:
            l += 1
        elif dr>d:
            r -= 1
        elif dl==d:
            l += 1
        elif dr==d:
            r -= 1
        else:
            break
        
    print(p[l-1]+((l+r)*(r-l+1))+p[n]-p[r])
    

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()