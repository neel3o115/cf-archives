# def frequency_array(arr):
#     freq = {}
#     for num in arr:
#         freq[num] = freq.get(num, 0) + 1
#     return freq

# def fun(arr, x):
#     n = len(arr)
#     l, r = 0, 1
#     pairs = []
    
#     while r < n:
#         if arr[r] - arr[l] < x:
#             pairs.append((arr[l], arr[r]))
#             r += 1
#         else:
#             l += 1
#             if l == r:
#                 r += 1
#     return pairs

# t = int(input())

# for _ in range(t):
#     n = int(input())
#     arr = list(map(int, input().split()))
    
#     freq = frequency_array(arr)
#     pppp = []
#     dddd = []

#     for k,v in freq.items():
#         if v > 2:
#             pppp.append(k)
#             dddd.append(k)
#         elif v == 2:
#             pppp.append(k)
#         else:
#             dddd.append(k)
    
#     if len(pppp) >= 2:
#         print(pppp[0], pppp[0], pppp[1], pppp[1])
#         continue
    
#     arr = sorted(dddd)
#     result = []
#     for num in pppp:
#         x = 2 * num
#         pairs = fun(arr, x)
#         if pairs:
#             result = [pairs[0][0], pairs[0][1], num, num]
#             break
    
#     if result:
#         print(*result)
#     else:
#         print(-1)

def get_pairs(arr, val):
    n = len(arr)
    i, j = 0, 1
    res = []

    while j < n:
        if arr[j] - arr[i] < val:
            res.append((arr[i], arr[j]))
            j += 1
        else:
            i += 1
            if i == j:
                j += 1
    return res

def fa(arr):
    cnt = {}
    for n in arr:
        cnt[n] = cnt.get(n, 0) + 1
    return cnt

t = int(input())

for a in range(t):
    n = int(input())
    nums = list(map(int, input().split()))

    counts = fa(nums)
    dup = []
    non_dup = []

    for num, freq in counts.items():
        if freq > 2:
            dup.append(num)
            non_dup.append(num)
        elif freq == 2:
            dup.append(num)
        else:
            non_dup.append(num)

    if len(dup) >= 2:
        print(dup[0], dup[0], dup[1], dup[1])
        continue

    nums = sorted(non_dup)
    ans = []
    for num in dup:
        target = 2 * num
        pair_list = get_pairs(nums, target)
        if pair_list:
            ans = [pair_list[0][0], pair_list[0][1], num, num]
            break

    if ans:
        print(*ans)
    else:
        print(-1)
