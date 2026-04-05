PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,m = map(int,input().split())

    fr = [n//m]*m

    for i in range((n//m)*m+1,n+1):
        fr[i%m] += 1 
    
    res = 0

    for i in range(m):
        for j in range(m):
            if ((i%m)**2 + (j%m)**2)%m == 0:
                res += fr[i]*fr[j]
    
    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()