t = int(input())

for _ in range(t):
    n = int(input())
    lis = list(map(int, input().split()))

    count = 0
    mxx = float('-inf') 
    smm = 0


    for i in range(n):
        smm += lis[i]
        mxx = max(mxx, lis[i])


        if 2*mxx == smm:
            count += 1
    
    print(count)