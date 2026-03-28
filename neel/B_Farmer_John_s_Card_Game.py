def fun(mat, k):
    nee = []
    for row in mat:
        new = [x % k for x in row]
        nee.append(new)
    return nee

t = int(input())

for _ in range(t):
    n, m = map(int, input().split()) 
    
    mm = []
    for i in range(n):
        a = list(map(int, input().split()))
        mm.append(a)

    if n == 1:
        print(1)
    
    else:
        jee = fun(mm, n)

        kee = dict()
        count = 0
        for i in range(n):
            if all (x == jee[i][0] for x in jee[i]):
                count += 1
                kee[jee[i][0]] = i + 1
        
        if count == len(jee):
            keeee = {key: kee[key] for key in sorted(kee)}
            ooo = []
            for k,v in keeee.items():
                ooo.append(v)
            print(*ooo)

        else:
            print(-1)