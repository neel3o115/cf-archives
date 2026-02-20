PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

coin = [1,3,6,10,15]

dp = [INF]*31
dp[0] = 0

for i in range(1,31):
    for j in range(5):
        if i-coin[j] >= 0:
            dp[i] = min(dp[i],1+dp[i-coin[j]])

def solve():
    n = int(input())
    res = min((n//30)*2+dp[n%30],1+((n-15)//30)*2+dp[(n-15)%30] if n>=15 else INF)
    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()
