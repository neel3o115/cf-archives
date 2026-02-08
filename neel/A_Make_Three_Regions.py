PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = input()
    b = input()
    res = 0
    for i in range(1, n - 1):
        if a[i] == "." and b[i - 1] == b[i + 1] == "x" and a[i - 1] == a[i + 1] == "." and b[i] == ".":
            res += 1
        if b[i] == "." and a[i - 1] == a[i + 1] == "x" and b[i - 1] == b[i + 1] == "." and a[i] == ".":
            res += 1
        
    print(res)


def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()