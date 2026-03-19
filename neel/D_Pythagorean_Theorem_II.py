import math
n = int(input())
# arr = [x**2 for x in range(1, 10001)]
# print(arr)

count = 0

for i in range(1, n+1):
    for j in range(1, i):
        kk = i**2 - j**2

        if kk > 0:
            k = int(math.sqrt(kk))
            if k**2 == kk:
                if j >= k >= 1:
                    # print(i, j, k)
                    count += 1
    # print()

print(count)