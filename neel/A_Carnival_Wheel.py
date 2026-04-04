PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    l,a,b = map(int, input().split())

    mxx = a
    nee = set()

    x = a

    while x not in nee:
        nee.add(x)
        x = (x+b)%l

        mxx = max(mxx,x)

    print(mxx)


def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()