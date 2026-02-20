PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def dig(x):
    res = [0]*10
    if x == 0:
        res[0] = 1
        return res

    while x != 0:
        res[x%10] += 1
        x //= 10

    return res

def fun(x):
    if x == 0:
        return 0
    
    s = 0
    while x:
        s += x % 10
        x //= 10
    return s

def solve():
    s = input()
    n = len(s)

    if len(s) == 1:
        print(s)
        return
    
    fr = [0]*10
    nee = 0

    for c in s:
        d = int(c)
        nee += d
        fr[d] += 1
    
    if nee % 2 == 0:
        a = nee // 2

        if 1 <= a <= 9 and fr[a] > 0:
            fr[a] -= 1

            sx = 0
            cnt = 0
            for i in range(10):
                sx += i * fr[i]
                cnt += fr[i]

            if sx == a and cnt > 0:
                x = ""
                for i in range(9, -1, -1):
                    x += str(i) * fr[i]

                print(x + str(a))
                return

            fr[a] += 1

    for b in range(1,10):

        if fr[b] == 0:
            continue

        a = nee - 2*b
        if a <= 0:
            continue

        if fun(a) != b:
            continue

        cur = fr.copy()
        cur[b] -= 1

        jee = dig(a)

        pos = True
        for i in range(10):
            if cur[i] < jee[i]:
                pos = False
                break

        if pos:
            for i in range(10):
                cur[i] -= jee[i]

            x = ""
            cnt = 0
            for i in range(9,-1,-1):
                x += str(i)*cur[i]
                cnt += cur[i]

            if cnt == 0:
                continue

            print(x + str(a) + str(b))
            return

def main():
    t = int(input()) 
    for _ in range(t):
        solve()

main()