t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    sf = [0 for i in range(n)]
    sf[-1] = a[-1]

    if n == 1:
        print(a[0])

    else:
        for i in range(n-2,-1,-1):
            sf[i] = sf[i+1]+a[i]

        b = [0 for i in range(n)]
        b[0] = 1 

        for i in range(1, n-1):
            if a[i]+sf[i+1] >= 0:
                b[i] = b[i-1]+1
            else:
                b[i] = b[i-1]
        
        if a[-1] >= 0:
            b[-1] = b[-2]+1
        else:
            b[-1] = b[-2]


        ans = 0
        for i in range(n):
            ans += b[i]*a[i]
        
        # print(*b)
        print(ans)