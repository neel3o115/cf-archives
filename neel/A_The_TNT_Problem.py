PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 150005
fac = [[] for _ in range(N)]

for i in range(1, N):
    for j in range(i, N, i):
        fac[j].append(i)

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ps = [0]*(n+1)

    for i in range(n):
        ps[i+1] = ps[i]+a[i]

    res = 0
    for f in fac[n]:
        mini = float('inf')
        mexa = 0
        
        for i in range(f,n+1,f):
            x = ps[i]-ps[i-f]
            mini = min(x,mini)
            mexa = max(x,mexa)
        
        res = max(res,mexa-mini)

    print(res)

def main():
    t = 1
    t = int(input())    
    for _ in range(t):
        solve()

main()