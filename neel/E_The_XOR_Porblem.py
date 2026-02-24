PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def msb(n):
    return 2**(len(bin(n)[2::])+1)-1

def solve():
    x,m = map(int,input().split())
    res = 0

    for y in range(1,min(msb(x),m+1)):
        a = x^y

        if a == 0:
            continue

        if (x%a == 0) or (y%a == 0):
            res += 1

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()