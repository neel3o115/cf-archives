PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ps = [0]*n 
    ps[0] = 0
    mx = a[0]

    for i in range(1,n):
        if a[i] >= mx:
            ps[i] = i
            mx = a[i]
        else:
            ps[i] = ps[i-1]

    res = 1
    crr = 0

    for i in range(1,n):
        if ps[i] != crr:
            res += 1 
            crr = ps[i]

    print(res)
     
def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()