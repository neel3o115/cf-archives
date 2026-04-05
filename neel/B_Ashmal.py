PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(input().split())

    s = a[0]

    for i in range(1, n):
        x = a[i]
        if x+s < s+x:
            s = x+s
        else:
            s = s+x
    
    print(s)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()