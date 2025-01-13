T = int(input())

for _ in range(T):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))

    count = 0
    count1 = 0

    for i in range(n):
        if a[i] < b[i]:
            count += 1
            count1 += b[i] - a[i]

    if count == 0:
        print("YES")
    elif count > 1:
        print("NO")
        
    else:
        count2 = 0
        for i in range(n):
            if a[i] - b[i] < count1:
                count2 += 1
        if count2 == 1:
            print("YES")
        else:
            print("NO")