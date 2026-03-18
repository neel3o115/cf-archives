u, d, n = map(int, input().split())
uu = u+n
dd = d+n

if u > dd:
    print("+")
elif d > uu:
    print("-")
elif u == d and n == 0:
    print(0)
else:
    print("?")