t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = input()


    pxor = [0]*(n+1)
    for i in range(n):
        pxor[i+1] = pxor[i]^a[i]

    zro = 0
    one = 0

    for i in range(n):
        if s[i] == '1':
            one = one^a[i]
        else:
            zro = zro^a[i]

    q = int(input())
    for i in range(q):
        o = list(map(int, input().split()))

        if o[0] == 1:
            l, r = o[1], o[2]

            x = pxor[r]^pxor[l-1]
            zro = zro^x
            one = one^x

        else:
            g = o[1]
        
            if g == 0:
                print(zro, end = " ")
            else:
                print(one, end = " ")
    
    print()