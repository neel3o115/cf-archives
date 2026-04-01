def fo(arr, x):
    l = 0
    r = len(arr) - 1

    while l < r:
        m = (l + r)//2

        if arr[m] == x:
            r = m
        
        if arr[m] < x:
            l = m + 1
        
        if arr[m] > x:
            r = m - 1

    if arr[r] == x:
        return r
    else:
        return -1 


def lo(arr, x):
    l = 0
    r = len(arr) - 1
    ans = -1 

    while l <= r:
        m = (l + r) // 2
        if arr[m] == x: 
            ans = m
            l = m + 1  

        elif arr[m] < x:
            l = m + 1

        else:
            r = m - 1

    return ans

arr = list(map(int, input().split()))
key = int(input())

print(arr[0:])

# for i in range(len(arr)):
#     print(arr[i] > i)


# jee = 0
# a = 0
# b = len(arr) - 1

# while a <= b:
#      mid = (a + b) // 2
#      if arr[mid] == key:
#          jee = 1
#          break
#      if arr[mid] < key:
#          a = mid + 1
#      if arr[mid] > key:
#          b = mid - 1

# print(jee)


# print(fo([1, 2, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11], 4)) 
# print(lo([1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 10], 5)) 
                                