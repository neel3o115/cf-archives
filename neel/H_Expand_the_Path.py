t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    res = len(s)+1
    R = s.count('R')+1
    D = s.count('D')+1
    r = 0
    d = 0

    for i in range(len(s)):
        if s[i] == 'R':
            r += 1
        else:
            break
    
    for i in range(len(s)):
        if s[i] == 'D':
            d += 1
        else:
            break

    if R == 1:
        print(n)

    elif D == 1:
        print(n)

    else:
        if s[0] == 'R':
            res += (n-R)*(n-D)
            res += (D)*(n-R)
            res += (R-r)*(n-D)

        else:
            res += (n-R)*(n-D)
            res += (R)*(n-D)
            res += (D-d)*(n-R)

        print(res)