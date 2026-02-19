def check(x):
    if x <= 0:
        return 0
    if x == int(x):
        return 1
    return 0

t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())
    m1 = (a+c)/(2*b)
    m2 = (2*b-c)/a
    m3 = (2*b-a)/c

    if (check(m1) or check(m2) or check(m3)):
        print('YES')
    else:
        print('NO')