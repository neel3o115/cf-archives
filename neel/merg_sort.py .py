def merge_sort(arr, l, h):
    if len(arr) == 1:
        return arr
    
    if l >= h:
        return

    m = (l+h)//2
    merge_sort(arr, l, m)
    merge_sort(arr, m+1, h)
    merge(arr, l, m, h)

    return arr


def merge(arr, l, m, h):
    nee = []
    left = l
    right = m+1

    while (left <= m) and (right <= h):
        if arr[left] <= arr[right]:
            nee.append(arr[left])
            left += 1
        else:
            nee.append(arr[right])
            right += 1

    while left <= m:
        nee.append(arr[left])
        left += 1
    
    while right <= h:
        nee.append(arr[right])
        right += 1
    
    for i in range(len(nee)):
        arr[l + i] = nee[i]

n = int(input())
arr = list(map(int, input().split()))

print(*merge_sort(arr, 0, n-1))

