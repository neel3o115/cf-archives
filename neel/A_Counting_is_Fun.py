# # mod = 10**9 + 7
# # t = int(input())

# # for _ in range(t):
# #     n = int(input())
# #     arr = list(map(int, input().split()))

# #     count = 1
# #     nee = True

# #     for i in range(1, n - 1):
# #         if arr[i] == -1 and (arr[i - 1] < arr[i + 1] != -1):
# #             count *= arr[i + 1] - arr[i - 1] - 1
        
# #         if (arr[i - 1] >=  arr[i + 1] != -1):
# #             count = 0
# #             break
        
# #         if arr[i] != -1 and (arr[i] == arr[i+1]):
# #             nee = False
# #             break
        
# #     if not nee:
# #         count = 0
        
# #     print(count % mod)

# # mod = 10**9 + 7
# # t = int(input())

# # for _ in range(t):
# #     n = int(input())
# #     arr = list(map(int, input().split()))

# #     count = 1
# #     nee = True

# #     for i in range(1, n - 1):
# #         if arr[i] == -1:
# #             if arr[i - 1] < arr[i + 1]:
# #                 count *= arr[i + 1] - arr[i - 1] - 1
# #                 count %= mod
# #             else:
# #                 nee = False
# #                 break
        
# #         if arr[i] != -1 and arr[i] == arr[i + 1]:
# #             nee = False
# #             break

# #     if not nee:
# #         count = 0
        
# #     print(count)

# mod = 10**9 + 7
# t = int(input())

# for _ in range(t):
#     n = int(input())
#     arr = list(map(int, input().split()))
#     nee = 1
#     jee = True

#     for i in range(n - 1):
#         if arr[i] == -1:
#             if i > 0 and arr[i + 1] > arr[i - 1]:
#                 nee *= (arr[i + 1] - arr[i - 1] - 1)
#                 nee %= mod
#             else:
#                 nee = 0
#                 jee = False
#                 break
#         if arr[i + 1] <= arr[i] and arr[i + 1] != -1 and arr[i] != -1:
#             nee = 0
#             jee = False
#             break

#     print(nee if jee else 0)
