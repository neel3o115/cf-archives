PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 104800
isprime = [1]*N
isprime[0] = 0
isprime[1] = 0

for i in range(2,N):
    if isprime[i]:
        for j in range(i*i,N,i):
            isprime[j] = 0  

prime = []

for i in range(N):
    if isprime[i]:
        prime.append(i)

def solve():
    n = int(input())
    a = []

    for i in range(n):
        a.append(prime[i]*prime[i+1])

    print(*a)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()