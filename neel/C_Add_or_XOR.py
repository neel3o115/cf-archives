PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    a,b,x,y = map(int,input().split())

    if (a > b):
        if (a^1 != b):
            print(-1)
        else:
            print(y)
        return

    res = 0
    while a != b:
        if a%2 == 0:
            res += min(x,y)
        else:
            res += x
        a = a+1 

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()