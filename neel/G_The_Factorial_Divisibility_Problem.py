PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,x = map(int,input().split())
    a = list(map(int, input().split()))

    dp = [0]*(x+1)

    for i in range(n):
        dp[a[i]] += 1
    
    for i in range(x):
        if dp[i]%(i+1) != 0:
            print('No')
            return 
        else:
            dp[i+1] += dp[i]//(i+1)
        
    print('Yes')

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()