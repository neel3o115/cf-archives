n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

res = 0

fa = {}
fb = {}

for i in range(n):
    fa[a[i]] = fa.get(a[i],0)+1

for i in range(m):
    fb[b[i]] = fb.get(b[i],0)+1

pre = -1000000009
for i in range(n):
    if a[i] != pre:
        res += fa[a[i]]*fb.get(a[i],0)
        pre = a[i]

print(res)