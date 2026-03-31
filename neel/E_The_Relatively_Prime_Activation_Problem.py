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

def fac(x):
    res = set()

    while x > 1:
        res.add(spf[x])
        x //= spf[x]
        
    return res

def solve():
    n,m = map(int,input().split())

    active = [0]*(n+1)
    prime = [0]*(n+1)

    for i in range(m):
        op,x = input().split()
        x = int(x)

        if op == '+':
            if active[x]:
                print('Already on')
                continue 
            
            factor = fac(x)
 
            safe = True
            y = 0

            for f in factor:
                if prime[f] > 0:
                    y = prime[f]
                    safe = False
                    break
            
            if safe:
                active[x] = 1
                for f in factor:
                    prime[f] = x
                print('Success')
            else:
                print(f"Conflict with {y}")
            
        else:
            if active[x] == 0:
                print('Already off')
                continue 
            
            active[x] = 0
            factor = fac(x)

            for f in factor:
                prime[f] = 0
            
            print('Success')

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()