import math

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def fun(a,b,n,lcm):
    if n < max(a,b):
        return n

    res = max(a,b)*((n//lcm)-1) + max(a,b)-1

    u = lcm*(n//lcm)
    for x in range(u,min(u+max(a,b),n+1)):
        if (x%a)%b == (x%b)%a:
            res += 1 
    
    return res

def solve():
    a,b,q = map(int,input().split())
    lcm = math.lcm(a,b)

    res = [0]*q
    for i in range(q):
        l,r = map(int,input().split())

        nee = fun(a,b,l-1,lcm)
        jee = fun(a,b,r,lcm)

        res[i] = r-(l-1) - (jee-nee)
    
    print(*res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()