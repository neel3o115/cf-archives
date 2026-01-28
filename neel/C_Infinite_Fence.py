import math
t = int(input())

for _ in range(t):
    r, b, k = map(int, input().split())
    print(math.lcm(r, b))
    print(math.gcd(r, b))
    print()
