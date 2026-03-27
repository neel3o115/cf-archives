PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,m,k = map(int,input().split())
    a = list(map(int,input().split()))

    rule = [[0 for i in range(20)] for j in range(20)]

    for i in range(k):
        x,y,c = map(int,input().split())
        rule[x][y] = c

    # dp[mask][last]
    dp = [[0 for i in range(20)] for j in range(20)]  
    res = 0

    for i in range(1<<n):
        pre = 0
        sat = 0

        

        # if i.bit_count() == m:
        #     for j in range(n):
        #         if i & (1<<j):
        #             sat += a[j]
        #             sat += rule[pre][j+1]
        #             pre = j+1
            
        #     res = max(res,sat)
        
    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()