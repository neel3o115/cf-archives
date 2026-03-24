t = int(input())

for _ in range(t):
    n, m = map(int, input().split()) 
    x = input()
    s = input()
    nee = 1 if (s.count(s[0]) == len(s)) and (x.count(x[0]) == len(x)) else 0
    # nee = x in s

    res = -1

    if nee:
        res = 0
        y = len(x)

        while (y < len(s)):
            res += 1
            y *= 2
        
        print(res)
    else:
        if s in x:
            res = 0
        elif s in x+x:
            res = 1
        elif s in x+x+x+x:
            res = 2

        print(res)