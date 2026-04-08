t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    vis = [0]*(2*n)

    ans = 0

    for i in range(n):
        cr = a[i]
        tm = 0

        for j in range(n):
            pass
