PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, x, y = map(int, input().split())
    s = input().strip()
    x = abs(x)
    y = abs(y)

    c8 = s.count('8')
    c4 = s.count('4')
    x = max(0, x-c8)
    y = max(0, y-c8)

    if x+y <= c4:
        print("YES")
    else:
        print("NO")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()