PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0]*n
    c = [0]*n

    for i in range(n):
        x = a[i]
        while x%2 == 0:
            b[i] += 1
            x = x//2
        
        x = a[i]
        while x%3 == 0:
            c[i] += 1
            x = x//3
    
    nee = []
    for i in range(n):
        nee.append([-c[i], b[i], i])

    nee.sort()

    res = []
    for i in range(n):
        res.append(a[nee[i][2]])
    print(*res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()