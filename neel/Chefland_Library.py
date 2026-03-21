t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))  
    arr.reverse()
    new = []
    wen = []

    for i in range(n):
        if arr[i] not in wen:
            wen.append(arr[i])
            new.append(n-i)
            # print(new)
    

    penatly = sum(new)
    print(penatly)


