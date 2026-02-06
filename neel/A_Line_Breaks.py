t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    arr = []
    strip = ""
    count = 0
    for i in range(n):
        s = input()
        arr.append(s)

    for i in arr:
        count += 1
        strip += i
        if len(strip) > m:
            print(count-1)
            break
        elif len(strip) == m:
            print(count)
            break
    

