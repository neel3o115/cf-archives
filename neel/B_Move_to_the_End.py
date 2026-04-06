t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    nee = [0]*n
    mxx = 0

    pre = [0] * n
    pre[0] = a[0]
    
    for i in range(1, n):
        pre[i] = max(pre[i-1], a[i])
    
    for i in range(n):
        if n - i - 1 >= 0:
            nee[i] = pre[n - i - 1]
        else:
            nee[i] = None 


    ss = [0]*n
    ss[n-1] = a[n-1]

    for i in range(1, n):
        ss[n-i-1] = ss[n-i] + a[n-i-1]
    ss.reverse()

    for i in range(n-1):
        ss[i] = ss[i] - a[n-1-i] + nee[i]

    
    print(*ss)
    # print(pre)
    # print(nee)



