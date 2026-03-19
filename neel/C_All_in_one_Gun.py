PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,h,k = map(int,input().split())
    a = list(map(int,input().split()))
    s = sum(a)

    x = h//s
    y = h%s

    ans = x*n + max(0,x-1)*k

    if y > 0:
        if x > 0:
            ans += k

        sff = a[:]

        for i in range(n-2,-1,-1):
            sff[i] = max(sff[i], sff[i+1])

        ps = 0
        mn = 10**18

        for i in range(n):
            ps += a[i]
            mn = min(mn, a[i])

            if ps >= y:
                ans += i+1
                break

            if i < n-1:
                new_ps = ps - mn + sff[i+1]
                if new_ps >= y:
                    ans += i+1
                    break

    print(ans)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()