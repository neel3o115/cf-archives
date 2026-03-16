PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0]*n

    if n == 1:
        print(a[0]+1)
        return 

    o = []
    e = []

    for i in range(n):
        if i%2 == 0:
            e.append(a[i])
        else:
            o.append(a[i])

    print(max(len(e)+max(e), len(o)+max(o)))

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()