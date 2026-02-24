t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    vis = [0] * 102

    for i in range(n):
        vis[a[i]] = 1

    for i in range(102):
        if (vis[i] == 0):
            print(i)
            break
