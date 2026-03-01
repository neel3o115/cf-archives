t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    arr.sort()

    l = 0
    r = n - 1
    count = 0

    while l < r:
        cs = arr[l] + arr[r]
        if cs == k:
            count += 1
            l += 1
            r -= 1  
        elif cs < k:
            l += 1  
        else:
            r -= 1 

    print(count)