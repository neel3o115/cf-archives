n = int(input())
res = 1

for i in range(n,n-5,-1):
    res *= i

res *= n*(n-1)*(n-2)*(n-3)*(n-4)//120

print(res)