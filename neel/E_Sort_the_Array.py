n = int(input())
arr = list(map(int, input().split()))

nee = sorted(arr)
lis = []

for i in range(n-1):
    if arr[i] > arr[i+1]:
        lis.append(i)

print(lis)