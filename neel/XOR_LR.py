n = int(input())
a = list(map(int, input().split()))

pxor = [[0 for i in range(21)] for i in range(n+1)]

for i in range(n):
    s = bin(a[i])[2::]
    s = s[::-1]

    for j in range(len(s)):
        pxor[i+1][j] = pxor[i][j] 

        if s[j] == '1':
            pxor[i+1][j] += 1
    
q = int(input())
for i in range(q):
    l, r = map(int, input().split())
    ans = 0

    for bit in range(21):
        if (pxor[r][bit] - pxor[l-1][bit])%2 == 1:
            ans += 1<<bit

    print(ans)