PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

import sys
sys.setrecursionlimit(10**7)

def mod_pow(a, b, mod=MOD2):
    res = 1
    a %= mod
    while b > 0:
        if b & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        b >>= 1
    return res

def dfs(u, parent, adj, a, sum_abs, neg_cnt):
    if parent == -1:
        sum_abs[u] = abs(a[u])
        neg_cnt[u] = 1 if a[u] < 0 else 0
    else:
        sum_abs[u] = sum_abs[parent] + abs(a[u])
        neg_cnt[u] = neg_cnt[parent] + (1 if a[u] < 0 else 0)

    for v in adj[u]:
        if v != parent:
            dfs(v, u, adj, a, sum_abs, neg_cnt)

def solve():
    n = int(input())
    arr = [0] + list(map(int, input().split()))
    
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    sum_abs = [0] * (n+1)
    neg_cnt = [0] * (n+1)

    dfs(1, -1, adj, arr, sum_abs, neg_cnt)

    res = [0]*(n)

    for i in range(1, n+1):
        if neg_cnt[i]%2 == 0:
            neg_cnt[i] = 1
        else:
            neg_cnt[i] = -1

    for i in range(1, n+1):
        res[i-1] = neg_cnt[i]*sum_abs[i]
    
    res.sort()

    # print(res)

    if res[-1] > 0:
        print(mod_pow(2, res[-1]))
        return
    else:
        print(-mod_pow(2, -res[-1]))
        return

def main():
    t = 1
    t = int(input())
    for _ in range(t):
        solve()


main()
