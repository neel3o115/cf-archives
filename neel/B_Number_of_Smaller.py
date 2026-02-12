n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = 0
j = 0
s = a[0]
cn = 0

c = [0] * len(b)

while i < n and j < m:
    if a[i] < b[j]:
        cn += 1
        i += 1
    
    else: 
        c[j] = cn
        j += 1

for k in range(j, m):
    c[k] = cn

print(*c)

# lowerbound = smallest index of the element which is greater than or equal to the key
def lowerBound(arr, x):
    l = 0
    r = len(arr) - 1
    ans = len(arr)

    while l <= r:
        m = (l + r) // 2

        if arr[m] >= x:
            r = m - 1
            ans = m

        else:
            l = m + 1 
    
    return ans