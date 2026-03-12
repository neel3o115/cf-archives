lis = list(map(int, input().split()))
dif = [lis[0]]
for i in range(1,len(lis)):
    dif.append(lis[i] - lis[i-1])

print(dif)
# t = int(input())

# for _ in range(t):
#     l, r, x = map(int, input().split())
#     dif[l] += x 
#     if r!=len(dif)-1:
#         dif[r+1] -= x

# a = dif[0]
# sum = [a]
# for i in range(1,len(dif)):
#     sum.append(a+dif[i])
#     a = a + dif[i]
# print(sum)
