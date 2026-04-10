n = int(input())
a = list(map(int, input().split()))

pand = [[0 for i in range(21)] for i in range(n+1)]

for i in range(n):
    s = bin(a[i])[2::]
    s = s[::-1]

    for j in range(21):
        pand[i+1][j] = pand[i][j] 

        if j >= len(s):
            continue

        if s[j] == '1':
            pand[i+1][j] += 1

# for cc in pand:
#     print(*cc)    

q = int(input())

for i in range(q):
    l, r = map(int, input().split())
    ans = 0

    for bit in range(21):
        if (pand[r][bit] - pand[l-1][bit]) == r-l+1:
            ans += 1<<bit

    print(ans)