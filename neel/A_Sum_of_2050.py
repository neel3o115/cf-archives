t = int(input())

for _ in range(t):
    n = int(input())
    nee = n//2050

    if ((n%(2050)) != 0):
        print(-1)
    
    else:
        jee = str(nee)
        ans = 0

        for i in jee:
            ans += int(i)
        
        print(ans)

