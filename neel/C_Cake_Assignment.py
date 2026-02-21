t = int(input())

for _ in range(t):
    n, k = map(int, input().split()) 
    a = 2**n
    b = 2**n

    c = k
    d = 2**(n+1)-k 

    ans = []
    if (c == d):
        print(0)
        print(*ans)
    else:

        while (c != d):
            if c > d:
                c = c-d
                d = 2*d
                ans.append(2)
            else:
                d = d-c
                c = 2*c
                ans.append(1)

        ans.reverse()
        print(len(ans))
        print(*ans)


