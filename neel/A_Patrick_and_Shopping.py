a, b, c = map(int, input().split())

d1 = a+b+c
d2 = 2*a + 2*b
d3 = 2*a + 2*c
d4 = 2*b + 2*c

print(min(d1,d2,d3,d4))