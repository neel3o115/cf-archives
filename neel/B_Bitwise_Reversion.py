t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())

    if ((a&b) == (b&c) == (a&c)):
        print("YES")
    else:
        print("NO")
