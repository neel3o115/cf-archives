PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    r1 = list(map(int, input().split()))
    r2 = list(map(int, input().split()))
    mat = []
    mat.append(r1)
    mat.append(r2)

    mini = [row[:] for row in mat]
    mexi = [row[:] for row in mat]

    for i in range(1, n):
        mexi[0][i] = max(mexi[0][i], mexi[0][i-1])

    for i in range(n-2, -1, -1):
        mexi[1][i] = max(mexi[1][i], mexi[1][i+1])
    
    for i in range(1, n):
        mini[0][i] = min(mini[0][i], mini[0][i-1])

    for i in range(n-2, -1, -1):
        mini[1][i] = min(mini[1][i], mini[1][i+1])

    rang = [INF]*(2*n)

    for i in range(n):
        l = min(mini[0][i], mini[1][i])-1
        r = max(mexi[0][i], mexi[1][i])-1
        rang[l] = min(rang[l], r)
    
    for i in range(2*n-2,-1,-1):
        rang[i] = min(rang[i+1], rang[i])

    res = 0

    for i in range(2*n):
        res += max(2*n-rang[i], 0)

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()