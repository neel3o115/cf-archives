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

# upperbound = smallest index of the element which is greater than the key
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

t = int(input())
arr = list(map(int, input().split()))
arr.sort()

q = int(input())
nee = []
for _ in range(q):
    l, r = map(int, input().split())

    a = lowerBound(arr, l)
    b = upperBound(arr, r)

    nee.append(b - a)

print(*nee)
