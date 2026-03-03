# lowebound = smallest element which is greater than or equal to x

arr = list(map(int, input().split()))
x = int(input())

l = 0
r = len(arr) - 1
ans = len(arr)

while l <= r:
    m = (l + r) // 2

    if arr[m] >= x:
        ans = m
        r = m - 1

    else:
        l = m + 1
    
    