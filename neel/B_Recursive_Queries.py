PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def rec(n):
    if n<10:
        return n
    
    s = str(n)
    res = 1

    for i in s:
        if i!='0':
            res *= int(i)

    return rec(res)

N = 1000006

g = [0]*N

for i in range(1,N):
    g[i] = rec(i)

pr = [[0 for i in range(N)] for j in range(10)]

for i in range(1,10):
    for j in range(1,N):
        if g[j] == i:
            pr[i][j] = pr[i][j-1]+1 
        else:
            pr[i][j] = pr[i][j-1]

def solve():
    l,r,k = map(int,input().split())
    print(pr[k][r]-pr[k][l-1])

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()