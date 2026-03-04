n = int(input())
x = 2*n - 2

res = 0

for start in range(0,x-n+1):
    ways = 4 

    for pos in range(x):
        if start <= pos < start+n:
            continue
        if pos == start-1 or pos == start+n:
            ways *= 3
        else:
            ways *= 4

    res += ways

print(res)
