n,x = map(int,input().split())
a = list(map(int,input().split()))

res = 0
nee = {0}
smm = 0

for i in range(n):
    if smm+a[i]-x in nee:
        res += 1
    smm += a[i]
    nee.add(smm)
    
print(res)