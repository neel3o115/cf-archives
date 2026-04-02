PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    yes = "Yes"
    no = "No"

    if k in a:
        print(yes)
        return

    if k >= max(a):
        print(yes)
        return

    if k <= min(a):
        print(yes)
        return

    print(no)
    return

def main():
    t = 1
    t = int(input())        
    for _ in range(t):
        solve()

main()