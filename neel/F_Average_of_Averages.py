t = int(input())

N = 200000
p = [0]*(N+1)

for i in range(1,N+1):
    p[i] = p[i-1]+1/i

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    deno = (n*(n+1))//2
    numo = 0

    m = p[n]
    l = 0

    k = n//2

    for i in range(n,k,-1):
        z = a[i-1]+a[n-i]
        if i-1 == n-i:
            z = a[i-1]

        y = n+1-i
        x = (1/i)
        xx = (1/(n+1-i))

        numo += (y*m)*z+l*z
        m -= x+xx
        l += (n+1)*x
    
    res = numo / deno
    print(round(res, 6))