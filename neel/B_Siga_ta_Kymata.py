PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    x = input()

    mini = -1
    mexi = -1

    for i in range(n):
        if a[i] == n:
            mexi = i
        if a[i] == 1:
            mini = i
        if x[i] == '1' and (a[i] == 1 or a[i] == n or i == 0 or i == n-1):
            print(-1)
            return
    
    print(5)
    print(min(mexi, mini)+1, max(mexi, mini)+1)
    print(1, mini+1)
    print(1, mexi+1)
    print(mini+1, n)
    print(mexi+1, n)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()