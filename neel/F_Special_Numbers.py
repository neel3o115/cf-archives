PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,k = map(int,input().split())
    b = bin(k)[2::]
    b = b[::-1]

    res = 0

    for i in range(len(b)):
        if b[i] == '1':
            res = (res+n**(i))%MOD1
    
    print(res%MOD1)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()