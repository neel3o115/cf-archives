t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    
    mxx = sum(arr)
    crr = arr.copy()


    for k in range(1, n):

        dff = abs(crr[-1] - crr[0])
        if dff > mxx:
            mxx = dff

        da = []
        if crr[-1] > crr[0]:
            arr.reverse()
            for i in range(len(crr) - 1):
                da.append(crr[i+1] - crr[i])
            crr = da
        
        else:
            for i in range(len(crr) - 1):
                da.append(crr[i+1] - crr[i])
            crr = da

    if n == 0:
        mxx = 0
    
    print(mxx)

