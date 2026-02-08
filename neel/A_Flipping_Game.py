PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    tot = sum(a)
    nee = 0

    for i in range(n):
        zro = 0
        one = 0

        for j in range(i, n):
            if a[j] == 0:
                zro += 1
            else:
                one += 1

            nee = max(nee, zro-one)

    if tot == n:
        print(tot-1)
        return
    
    print(tot+nee)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()