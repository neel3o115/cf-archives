PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    l = len(str(n))
    y = n

    a = []
    b = []

    par = 0

    for i in range(l):
        x = y%10
        y = y//10

        q = x//2
        p = x-q

        if p != q:
            par = 1-par

        if par:
            a.append(p*(10**i))
            b.append(q*(10**i))
        else:
            b.append(p*(10**i))
            a.append(q*(10**i))

    print(sum(a),sum(b))


def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()