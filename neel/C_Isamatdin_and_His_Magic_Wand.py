t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    o = 0
    e = 0

    for i in range(n):
        if a[i]%2 == 0:
            o += 1
        else:
            e += 1
        
    if (o == 0 or e == 0):
        print(*a)
    else:
        a.sort()
        print(*a)