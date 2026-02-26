PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def dfs(node,adj,vis,par):
    if vis[node] != 0:
        return
    
    vis[node] = par
    
    for i in adj[node]:
        dfs(i,adj,vis,par)

def solve():
    x = 1
    n = int(input())
    p = list(map(int, input().split()))

    adj = [[] for i in range(n+1)]
    vis = [0]*(n+1)

    for i in range(n):
        x = i+1
        y = p[i]
        if y >= x:
            adj[x].append(y)

    for i in range(1,n+1):
        dfs(i,adj,vis,i)
    
    vis.sort()
    x = 0

    for i in range(1,n+1):
        if vis[i] != vis[i-1]:
            x += 1
    print(x)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()