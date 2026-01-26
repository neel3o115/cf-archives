PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    p = list(map(int, input().split()))
    a = list(map(int, input().split()))
    b = [-1]*n

    i = 0
    j = 0 

    while (i<n) and (j<n):
        if p[i] == a[j]:
            b[j] = i
            j += 1
        else:
            i += 1

    if b == sorted(b):
        print("YES")
    else:
        print("NO")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()