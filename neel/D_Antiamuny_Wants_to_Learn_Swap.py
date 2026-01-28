t = int(input())

for _ in range(t):
    n, q = map(int, input().split()) 
    a = list(map(int, input().split()))

    for _ in range(q):
        l, r = map(int, input().split())
        l -= 1
        r -= 1
        nee = a[l:r+1]
        jee = sorted(nee)

        i = 0
        while i < len(nee)-1:
            if nee[i] < nee[i+1]:
                i += 1
            else:
                nee[i], nee[i+1] = nee[i+1], nee[i]
                i += 2

        if nee == jee: 
            print("YES")
        else:
            print("NO")
