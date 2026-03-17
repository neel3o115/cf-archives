t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    k = int(input())

    mina = min(a)
    mexa = max(a)

    if mina <= k <= mexa:
        print("YES")
    else:
        print("NO")