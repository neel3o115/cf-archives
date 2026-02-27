def check(x):
    curr = 0
    no = 0
    for i in arr:
        if curr + i <= x:
            curr += i
        else:
            no += 1
            curr = i
    return no+1


n,k = map(int, input().split())
arr = list(map(int, input().split()))
l = max(arr)
r = sum(arr)
ans = 0

while l <= r:
    m = (l + r) // 2
    if check(m) <= k:
        ans = m
        r = m - 1
    else:
        l = m + 1
print(ans)