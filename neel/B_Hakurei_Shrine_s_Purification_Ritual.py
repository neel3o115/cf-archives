# import math

# def gcd(a,b,c):
#     if a == b == 1:
#         return c
#     if a > b:
#         return gcd(a-b,b,c+1)
#     return gcd(a,b-a,c+1)

t = int(input())

for _ in range(t):
    s = int(input())
    

# res = 0
# for i in range(1,1000):
#     for j in range(1,1000):
#         if (math.gcd(i,j) == 1) and (gcd(i,j,0) <= 6):
#             print(i,j)
#             res += 1

# print(res)

# print(gcd(1,3,0))