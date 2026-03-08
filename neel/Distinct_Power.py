def fun(arr):
    n = len(arr)
    lis = sorted(arr)

    new = []
    for i in range(n):
        idx = lis.index(arr[i])
        new.append(n-idx)

    return new

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    new = []
    for index, value in enumerate(arr):
        new.append([index, value])

    print(new)

    


        