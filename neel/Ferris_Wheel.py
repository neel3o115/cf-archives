n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

no = 0
l = 0
r = n - 1

while l <= r:
    if arr[l] + arr[r] <= k:
        no += 1
        l += 1
        r -= 1

    else:
        no += 1
        r -= 1

print(no)