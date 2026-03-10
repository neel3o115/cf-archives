PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 500001
spf = [i for i in range(N)]

for i in range(2,N):
    if spf[i] == i:
        for j in range(i*i,N,i):
            if spf[j] == j:
                spf[j] = i

num = [[] for i in range(N)]
for i in range(1,N):
    for j in range(i,N,i):
        num[j].append(i)

def facotize(n):
    res = {}

    while n!=1:
        res[spf[n]] = res.get(spf[n],0)+1
        n = n//spf[n]
    
    return res

dp = [-1]*N

def solve():
    n = int(input())

    if dp[n] != -1:
        print(dp[n])
        return 

    fac = num[n]
    nee = facotize(n)
    res = 0

    for i in fac:
        x = facotize(i)
        y = 1

        for prime in x: 
            y *= prime**nee[prime]
        res += len(num[n//y])

    dp[n] = res
    print(dp[n])

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()