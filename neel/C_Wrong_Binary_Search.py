def transform(arr, l, r):
    for i in range(l, r):
        if i == l:
            arr[i] = r
        else:
            arr[i] = arr[i]-1

def solve(n, s):
    a = []
    b = []
    c = []
    nee = [i for i in range(1, n+1)]

    cr = s[0]
    ln = 1
    for i in range(1, n):
        if s[i] != cr:
            if (cr == '0'):
                a.append(ln)
            b.append(ln)
            c.append(cr)
            cr = s[i]
            ln = 1
        else:
            ln += 1

    if ln:
        if (cr == '0'):
            a.append(ln)
        b.append(ln)
        c.append(cr)
    
    if len(a) == 0:
        print("YES")
        print(*nee)
        return 
    
    for i in a:
        if i == 1:
            print("NO")
            return

    # print(s)
    # print(*b)
    # print(*c)

    idx = 0
    for i in range(len(b)):
        if c[i] == '0':
            transform(nee, idx, idx+b[i])
        idx += b[i]


    print("YES")
    print(*nee)
    return


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        s = input().strip()
        solve(n, s)

