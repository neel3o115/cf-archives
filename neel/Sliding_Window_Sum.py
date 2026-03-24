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

    nee = 0

    for i in range(k):
        nee += v[i]
    
    res = nee

    for i in range(k,n):
        nee += v[i]-v[i-k]
        res ^= nee

    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()
