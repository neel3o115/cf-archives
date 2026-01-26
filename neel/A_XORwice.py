t = int(input())

mx = 1000000000
mx = bin(mx)[2::]
n = len(mx)

for _ in range(t):
    aa,bb = map(int,input().split())
    a = bin(aa)[2::].zfill(n)
    b = bin(bb)[2::].zfill(n)

    c = 0

    for i in range(n-1,-1,-1):
        if (a[i] == b[i] == '0'):
            continue
        elif (a[i] == b[i] == '1'):
            c += 2**(i)

    print((aa^c)+(bb^c))