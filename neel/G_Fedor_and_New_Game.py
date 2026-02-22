PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,m,k = map(int,input().split())
    p = []
    bp = []

    mx = 2**(n)-1
    mx = bin(mx)[2::]

    for i in range(m+1):
        pi = int(input())
        p.append(pi)
        bp.append(bin(pi)[2::].zfill(len(mx)))
    
    res = 0

    for i in range(m):
        cnt = 0

        for j in range(len(mx)):
            if bp[i][j] != bp[m][j]:
                cnt += 1
        
        if cnt <= k:
            res += 1 
    
    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()