t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    pos = False
    
    for i in range(min(n,50)):
        if pos:
            break
        for j in range(i+1,min(n,50)):
            if (a[j]%a[i])%2 == 0:
                print(a[i], a[j])
                pos = True
                break
    
    if not pos:
        print(-1)