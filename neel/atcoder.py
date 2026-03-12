n = int(input())
a = list(map(int,input().split()))

ps = [0]*(n)
ps[0] = a[0]

for i in range(1,n):
    ps[i] = ps[i-1]+a[i]

mxps = [0]*(n)
psps = [0]*(n)
mxps[0] = ps[0]
psps[0] = ps[0]


for i in range(1,n):
    mxps[i] = max(mxps[i-1],ps[i])
    psps[i] = psps[i-1]+ps[i]

res = 0

for i in range(n):
    res = max(res,psps[i]+mxps[i])

print(res)

print()

print(5^3^7)
print(3&7&2)
print(7|2|6)