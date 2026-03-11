import math

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

def solve(n):
    fac = num[n]
    nee = facotize(n)

    res = 0

    for i in fac:
        x = facotize(i)
        y = 1 

        for prime in x: 
            y *= prime**nee[prime]
        res += len(num[n//y])

    return res

def solve1(n):
    # n = int(input())

    fac = []
    res = 0

    for i in range(1,int(n**(0.5))+1):
        if n%i == 0:
            if i*i == n:
                fac.append(i)
            else:
                fac.append(i)
                fac.append(n//i)

    for i in range(len(fac)):
        for j in range(len(fac)):
            if math.gcd(fac[i],fac[j]) == 1:
                # print(fac[i],fac[j])
                res += 1
    
    return res
    # print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(1,t):
        # print(solve1(30))
        if solve(_) != solve1(_):
            print(_,solve(_),solve1(_))

main()