PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    a = list(map(int, input().split()))
    a.sort()

    for i in range(6):
        a[i] = -a[i]
    
    print(sum(a))

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()