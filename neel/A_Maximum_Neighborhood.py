PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    mat = [[i for i in range(1,n+1)] for i in range(n)]

    for i in range(n):
        for j in range(n):
            mat[i][j] += i*n

    res = 0

    for i in range(n):
        for j in range(n):
            temp = 0
            temp += mat[i][j]

            if i-1 >= 0:
                temp += mat[i-1][j]
            
            if i+1 < n:
                temp += mat[i+1][j]
            
            if j+1 < n:
                temp += mat[i][j+1]
            
            if j-1 >= 0:
                temp += mat[i][j-1]

            res = max(res, temp)
        
    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()