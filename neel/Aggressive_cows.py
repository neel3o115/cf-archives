# def check(arr, d):
#     c = 1
#     l = arr[0]

#     for i in range(1, len(arr)):
#         if arr[i] - l >= d:
#             c += 1
#             l = arr[i]
#     return c

# t = int(input())

# for _ in range(t):
#     n, k = map(int, input().split()) 
#     arr = []

#     for i in range(n):
#         arr.append(int(input()))
#     arr.sort()
#     l = 1
#     r = arr[-1] - arr[0]
#     ans = 0

#     while l <= r:
#         m = (l + r) // 2
#         if check(arr, m) >= k:
#             ans = m
#             l = m + 1
#         else:
#             r = m - 1   

#     print(ans)

# #     # for i in range(1, arr[-1] - arr[0] + 1):
# #     #     print(i, check(arr, i))
