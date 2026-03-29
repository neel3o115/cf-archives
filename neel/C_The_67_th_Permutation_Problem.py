PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = []

    i = 1
    j = 3*n

    while i<j:
        a.append(j)
        a.append(j-1)
        a.append(i)
        j -= 2
        i += 1

    print(*a)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()