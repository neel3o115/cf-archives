PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [sum(a)]*n
    
    for i in range(n):
        b[i] = (b[i]-a[i])/(n-1)
    
    c = []

    for i in range(n):
        if a[i] == b[i]:
            c.append(i+1)
    
    print(len(c))
    print(*c)

def main():
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()

main()