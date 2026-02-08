lis = list(map(int,input().split()))
a = lis[0]
sum = [a]

for i in range(1,len(lis)):
    sum.append(a+lis[i])
    a = a + lis[i]

t = int(input())
for i in range(t):
    l,r = map(int,input().split())
    if l!=0:
        print(sum[r]-sum[l-1])
    else:
        print(sum[r])

print(sum)