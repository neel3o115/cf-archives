PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    dp = [0] * n        
    mn = [0] * n         
    mx = [0] * n     
    sm = [0] * n      
    ln = [0] * n         

    ans = [0] * n    

    for i in range(n):
        mn[i] = mx[i] = sm[i] = a[i]
        ln[i] = 1
        dp[i] = 0  

        for j in range(i):
            new_mn = min(mn[j], a[i])
            new_mx = max(mx[j], a[i])
            new_sum = sm[j] + a[i]
            new_len = ln[j] + 1

            avg = new_sum // new_len
            f = max(new_mx - avg, avg - new_mn)

            if f > dp[i]:
                dp[i] = f
                mn[i] = new_mn
                mx[i] = new_mx
                sm[i] = new_sum
                ln[i] = new_len

        if i == 0:
            ans[i] = dp[i]
        else:
            ans[i] = max(ans[i-1], dp[i])

    print(*ans)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()