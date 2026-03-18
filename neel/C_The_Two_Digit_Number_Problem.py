def fun(n):
    m = n
    res = 0

    while n != 0:
        res += 1
        n //= 10

    p = 10 ** (res-1)
    return m//p, m%p, p-1, len(str(m)) > 1 and str(m)[1] == '0'


def rec(n, st, started):
    if n == 0:
        if started:
            return 1     
        else:
            return 0   # 00000.. 

    x,y,nn, flag = fun(n)
    ans = 0

    for i in range(x):
        if not started and i == 0:
            ans += rec(nn,st,False)
        else:
            nee = st|set([i])
            if len(nee) <= 2:
                ans += rec(nn,nee,True)

    nee = st|set([x])
    if flag:
        nee = nee|set([0])

    if len(nee) <= 2:
        temp = rec(y,nee,True)
        ans += temp

    return ans

n = int(input())
print(rec(n, set(), False))