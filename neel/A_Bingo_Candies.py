PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = []

    for i in range(n):
        row = list(map(int,input().split()))
        a.append(row)

    fr = {}

    for i in range(n):
        for j in range(n):
            fr[a[i][j]] = fr.get(a[i][j],0)+1
    
    lim = n*(n-1)

    for i in fr:
        if fr[i] > lim:
            print("NO")
            return 
    
    print("YES")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()