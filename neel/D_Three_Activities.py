PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    nee = []

    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    c = list(map(int,input().split()))

    for i in range(n):
        nee.append([a[i],b[i],c[i]])

    dp = [[0 for i in range(8)] for i in range(n+1)]

    for i in range(1,n+1):
        for j in range(8):
            for k in range(3):
                if (1<<k)&j == 0:
                    continue

                dp[i][j] = max(dp[i][j],dp[i-1][j],nee[i-1][k]+dp[i-1][j^(1<<k)])

    print(dp[n][7])

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()


# 000 0 0  0                                 
# 001 0 30 30                                    
# 010 0 30 30                                   
# 011 0 30 50                                   
# 100 0 30 30                                   
# 101 0 30                                    
# 110 0 30                                    
# 111 0 30                                    

# 000 0 0  0                                 
# 001 0 1  10                                
# 010 0 10 1                                  
# 011 0 10 20                                 
# 100 0 1                                   
# 101 0 1                                   
# 110 0 10                                   
# 111 0 10                                   