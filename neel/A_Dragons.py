PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    s, n = map(int, input().split())
    stag = []

    for i in range(n):
        x, y = map(int, input().split())
        stag.append([x, y])
    
    stag.sort()
    
    for i in range(n):
        x, y = stag[i]

        if s > x:
            s += y
        else:
            print("NO")
            return
    
    print("YES")

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()