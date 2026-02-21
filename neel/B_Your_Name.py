t = int(input())

for _ in range(t):
    n = int(input())
    a, b = input().split()

    fra = {}
    frb = {}

    for ch in a:
        fra[ch] = fra.get(ch, 0)+1
    
    for ch in b:
        frb[ch] = frb.get(ch, 0)+1
    
    ans = "YES"

    for ch in frb:
        if fra.get(ch, 0) < frb[ch]:
            ans = "NO"
            break
    
    print(ans)