def psq(s, i=1):
    while s >= i ** 2:
        if s == i ** 2:
            return True
        i += 2
    return False

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    t, r = 0, 0
    for x in a:
        t += x
        if psq(t):
            r += 1
    print(r)
