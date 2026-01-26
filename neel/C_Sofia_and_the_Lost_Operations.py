t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    m = int(input())
    d = list(map(int, input().split()))
    dd = {}

    for i in range(m-1):
        dd[d[i]] = dd.get(d[i],0)+1

    vis = [0]*n

    for i in range(n):
        if a[i] == b[i]:
            vis[i] = 1
            continue

        if b[i] in dd:
            if dd[b[i]] > 0:
                dd[b[i]] -= 1
                vis[i] = 1

    # print(vis)
    ans = "YES"
    count = 0

    for i in range(n-1):
        if vis[i] == 0:
            count += 1
            break
    
    if count > 1:
        ans = "NO"            

    print(ans)
