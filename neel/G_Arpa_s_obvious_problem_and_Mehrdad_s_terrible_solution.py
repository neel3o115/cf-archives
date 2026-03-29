n, k = map(int, input().split()) 
a = list(map(int, input().split()))

fr = {}
st = set()

for i in range(n):
    fr[a[i]] = fr.get(a[i], 0)+1

res = 0

if k == 0:
    for i in fr:
        res += (fr[i] * (fr[i]-1)) // 2
else:
    for i in range(n):
        if ((a[i], a[i]^k) in st) or ((a[i]^k, a[i]) in st):
            continue

        if (a[i]^k in fr):
            st.add((a[i],a[i]^k))

            res += fr[a[i]] * fr[a[i]^k]

print(res)