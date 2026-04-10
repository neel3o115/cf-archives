n = int(input())
a = list(map(int, input().split()))

res = set()
pre = set()

for i in range(n):
    crr = {a[i]}

    for p in pre:
        crr.add(p|a[i])

    pre = crr
    res |= pre

print(len(res))