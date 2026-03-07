lis = list(map(int, input().split()))
idx = []
for i in range(len(lis)):
    idx.append([lis[i],i])

sorted_idx = sorted(idx)
for i in range(len(lis)):
    print(sorted_idx[i][1],end=" ")
