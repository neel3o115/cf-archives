def lowerBound(arr, x):
    l = 0
    r = len(arr) - 1
    ans = -1

    while l <= r:
        m = (l + r) // 2

        if arr[m] <= x:
            l = m + 1
            ans = m

        else:
            r = m - 1
    
    return ans + 1

n, k = map(int, input().split())

arr = list(map(int, input().split()))
q = list(map(int, input().split()))

for i in range(k):
    x = q[i]
    print(lowerBound(arr, x))

