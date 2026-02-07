import math

t = int(input())

for _ in range(t):
    n, k = map(int, input().split()) 
    a = list(map(int, input().split()))

    cr = 1
    rs = 0

    for i in range(n):
        if a[i] == cr:
            cr += 1
        else:
            rs += 1

    print(math.ceil(rs/k))