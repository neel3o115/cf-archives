import math

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    g = a[0]
    for num in a[1:]:
        g = math.gcd(g, num)
    
    x = 2
    while math.gcd(x, g) != 1:
        x += 1
    
    if x <= 10**18:
        print(x)
    else:
        print(-1)