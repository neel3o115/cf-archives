PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def fun(s):
    res = 1

    crr = s[0]
    for i in range(1,len(s)):
        if s[i] == crr:
            continue
        else:
            res += 1
            crr = s[i]
    
    return res

def solve():
    n = int(input())
    s = input()

    ans = 0

    for i in range(n):
        ans = max(ans,fun(s[i:n]+s[0:i]))

    print(ans)


def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()