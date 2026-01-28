PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    s = input()

    vis = [0]*(n+1)
    cur = 1

    vis[cur] = 1

    for i in range(n):
        if s[cur-1] == 'R':
            cur += 1
        else:
            cur -= 1

        vis[cur] = 1

    ans = 0
    for i in range(1, n+1):
        if vis[i]:
            ans += 1

    print(ans)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()