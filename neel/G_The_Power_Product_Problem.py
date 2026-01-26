PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 100005
spf = [i for i in range(N)]

for i in range(2,N):
    if spf[i] == i:
        for j in range(i*i, N, i):
            if spf[j] == j:
                spf[j] = i

def fac(x,k):
    res = {}
    opp = {}

    while x > 1:
        res[spf[x]] = (res.get(spf[x],0)+1)%k
        x //= spf[x]
    
    for i in res:
        opp[i] = (k-res[i])%k

    y = 1
    z = 1

    for j in res:
        y *= j**(res[j])

    for j in opp:
        z *= j**(opp[j])

    return y,z

def solve():
    n,k = map(int,input().split())
    a = list(map(int, input().split()))

    nee = {}
    ans = 0

    for i in range(n):
        y,z = fac(a[i],k)
        ans += nee.get(z,0)
        nee[y] = nee.get(y,0)+1

    print(ans)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()