PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def factor(n):
    fac = []

    for i in range(1,int(n**0.5)+1):
        if n%i == 0:
            fac.append(i)
            if n != i*i:
                fac.append(n//i)
    fac.sort()
    return fac

def solve():
    n = int(input())
    s = input()

    d = [0]*(n+1)
    k = [0]*(n+1)

    for i in range(n):
        if s[i] == 'D':
            d[i+1] = d[i]+1
        else:
            d[i+1] = d[i]

        if s[i] == 'K':
            k[i+1] = k[i]+1
        else:
            k[i+1] = k[i]
    
    res = [0]*n

    for i in range(n):
        pass

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()