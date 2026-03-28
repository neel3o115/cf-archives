t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    l = [int(i) for i in s]

    # print(s)

    if l[0] == 0 or l[-1] == 0 or "00" in s:

        print(s.count("1"))
    else:
        maxa = float("inf")
        c = 0
        for i in range(n):
            if l[i]:
                c += 1
            else:  
                if c:
                    maxa = min(maxa,c)
                    c = 0

        maxa = min(maxa,c)

        


        print(s.count("1") + maxa)
        # print(maxa)


        


