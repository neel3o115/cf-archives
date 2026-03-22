n = int(input())
a = list(map(int, input().split()))
m = 21

por = [[0 for i in range(m)] for i in range(n+1)]

for i in range(n):
    for bit in range(m):
        por[i+1][bit] = por[i][bit]+((a[i]>>bit)&1)

q = int(input())

for i in range(q):
    l, r = map(int, input().split())

    ans = 0

    for bit in range(m):
        if por[r][bit] - por[l-1][bit] > 0:
            ans += 1<<bit

    print(ans)