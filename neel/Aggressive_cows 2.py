# # t = int(input())

# # for _ in range(t):
# #     n, c = map(int, input().split()) 
# #     arr = []

# #     for i in range(n):
# #         arr.append(int(input()))
    
# #     arr.sort()

# #     print(arr)

# #     lo = 0
# #     hi = arr[-1] - arr[0]

# #     while lo < hi:

# def covariance(arr1, arr2):
#     n = len(arr1)
#     mean1 = sum(arr1) / n
#     mean2 = sum(arr2) / n

#     summ = 0
#     for i in range(n):
#         summ += (arr1[i] - mean1) * (arr2[i] - mean2)
    
#     return summ / n

# def varince(arr):
#     n = len(arr)
#     mean = sum(arr) / n

#     summ = 0
#     for i in range(n):
#         summ += (arr[i] - mean) ** 2
    
#     return summ / n

# def correlation(arr1, arr2):
#     return covariance(arr1, arr2) / (varince(arr1) * varince(arr2)) ** 0.5  

# print(covariance([8, 9, 10, 11], [50, 55, 60, 65]))
# # print(correlation([10, 20, 30, 40], [5, 10, 15, 20]))

print(not(not(23%2)))