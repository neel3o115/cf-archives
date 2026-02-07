t = int(input())

for _ in range(t):
    n = int(input())
    b = list(map(int, input().split()))
    d = [0]*n
    a = [0]*n
    a[0] = 1

    for i in range(1, n):
        d[i] = b[i] - b[i-1]

    used = 1

    for i in range(1, n):
        idx = i+1
        if d[i]-idx == 0:
            a[i] = used+1
            used += 1
        else:
            a[i] = a[i-d[i]]

    print(*a)