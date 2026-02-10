import sys
sys.setrecursionlimit(10**7)

adj = [[] for _ in range(200005)]
color = [-1]*200005

def solve():
    n,m = map(int,input().split())

    for i in range(1,n+1):
        adj[i].clear()
        color[i] = -1

    for _ in range(m):
        u,v = map(int,input().split())
        adj[u].append(v)
        adj[v].append(u)

    ans = 0

    from collections import deque

    for i in range(1,n+1):
        if color[i] != -1:
            continue

        q = deque([i])
        color[i] = 0
        white = 1
        bip = True

        while q:
            u = q.popleft()

            for v in adj[u]:
                if color[v] == -1:
                    color[v] = color[u]^1
                    if color[v] == 0:
                        white += 1
                    q.append(v)
                elif color[v] == color[u]:
                    bip = False

        if bip:
            ans += white

    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

main()