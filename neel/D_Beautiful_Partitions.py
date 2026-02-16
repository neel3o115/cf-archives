t = int(input())

for _ in range(t):
    n, k = map(int, input().split()) 
    a = list(map(int, input().split()))

    mx = 0
    b = []
    cr = a[0]
    sz = 1

    for i in range(1, n):
        if cr > 0:
            mx += 1
            b.append(sz)
            sz = 1
            cr = a[i]
        else:
            sz += 1
            cr += a[i]

    if cr > 0:
        mx += 1
        b.append(sz)
    else:
        mx -= 1

    if mx >= k:
        print("YES")
        print(*b)
    else:
        print("NO")