t = int(input())
for i in range(t):
    a, b, c, d = map(int, input().split())
    x = [a + b, c - b, d - c]
    print(max((a + b == x) + (b + x == c) + (x + c == d) for x in x))