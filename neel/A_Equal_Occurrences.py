t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []

    cr = a[0]
    ln = 1
    for i in range(1, n):
        if a[i] != cr:
            b.append(ln)
            cr = a[i]
            ln = 1
        else:
            ln += 1

    if ln:
        b.append(ln)
    
    # print(*b)

    ans = 0

    for i in range(1, n+1):
        crr = 0
        for j in range(len(b)):
            if b[j] >= i:
                crr += i
        
        ans = max(ans, crr)
    
    print(ans)


