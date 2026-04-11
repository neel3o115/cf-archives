import sys
sys.setrecursionlimit(3000)

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 501
dp0 = [[-1 for i in range(2*N)] for i in range(2*N)]
dp1 = [[-1 for i in range(2*N)] for i in range(2*N)]

def solve():
    n,k = map(int,input().split())

    def rec(pos,crr,x):
        if x == k:
            if dp1[pos][crr] != -1:
                return dp1[pos][crr]
        else:
            if dp0[pos][crr] != -1:
                return dp0[pos][crr]

        if pos == 2*n:
            if crr == 0:
                return 1
            return 0
        
        res = 0
        if crr < x:
            res = rec(pos+1,crr+1,x)
        if crr > 0:
            res = (res+rec(pos+1,crr-1,x))%MOD1

        if x == k:
            dp1[pos][crr] = res
            return dp1[pos][crr]
        else:
            dp0[pos][crr] = res
            return dp0[pos][crr]
    
    print((rec(0,0,k)-rec(0,0,k-1))%MOD1)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()