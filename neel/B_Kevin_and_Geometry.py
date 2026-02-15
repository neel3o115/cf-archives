def frequency_array(arr):
    freq = {}
    for num in arr:
        freq[num] = freq.get(num, 0) + 1
    return freq

def fun(arr, x):
    n = len(arr)
    l, r = 0, 1
    pairs = []
    
    while r < n:
        if arr[r] - arr[l] < x:
            pairs.append((arr[l], arr[r]))
            r += 1
        else:
            l += 1
            if l == r:
                r += 1
    return pairs

t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    
    freq = frequency_array(arr)
    pppp = []
    dddd = []

    for k,v in freq.items():
        if v > 2:
            pppp.append(k)
            dddd.append(k)
        elif v == 2:
            pppp.append(k)
        else:
            dddd.append(k)
    
    if len(pppp) >= 2:
        print(pppp[0], pppp[0], pppp[1], pppp[1])
        continue
    
    arr = sorted(dddd)
    result = []
    for num in pppp:
        x = 2 * num
        pairs = fun(arr, x)
        if pairs:
            result = [pairs[0][0], pairs[0][1], num, num]
            break
    
    if result:
        print(*result)
    else:
        print(-1)