PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    l,r,k = map(int,input().split())

    if k > 9:
        print(0)
        return 
    
    d = 9//k+1

    a = pow(d,l,MOD1)
    b = pow(d,r,MOD1)

    print((b-a)%MOD1)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()