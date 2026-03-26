def binarySearch(arr, x):
    l = 0
    r = len(arr) - 1

    while l <= r:
        m = (l + r) // 2

        if arr[m] == x:
            return m
        
        if arr[m] < x:
            l = m + 1
        else: 
            r = m - 1
    
    return -1


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


def upperBound(arr, x):
    l = 0
    r = len(arr) - 1
    ans = len(arr)

    while l <= r:
        m = (l + r) // 2

        if arr[m] > x:
            r = m - 1
            ans = m

        else:
            l = m + 1
        
    return ans



def range(arr, x):
    l = 0
    r = len(arr) - 1

    first = -1
    last = -1

    a = lowerBound(arr, x)
    if arr[a] == x:
        first = a
        last = upperBound(arr, x) - 1
    
    return first, last


arr = list(map(int, input().split()))
key = int(input())

        
def binarySearch(arr, x):
    l = 0
    r = len(arr) - 1

    while l <= r:
        m = (l + r) // 2

        if arr[m] == x:
            return m
        
        if arr[m] < x:
            l = m + 1
        else: 
            r = m - 1
    
    return -1
