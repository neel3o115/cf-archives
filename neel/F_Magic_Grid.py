PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def checkcol(mat):
    res = [0]*len(mat)

    for i in range(len(mat)):
        for j in range(len(mat)):
            res[i] ^= mat[i][j]

    return res

def checkrow(mat):
    res = [0]*len(mat)

    for j in range(len(mat)):
        for i in range(len(mat)):
            res[j] ^= mat[i][j]

    return res

def solve():
    n = int(input())

    mat = [[0 for i in range(n)] for i in range(n)]
   

    nee = 0
    for x in range(n//4): 
        for y in range(n//4):
            for i in range(4): 
                for j in range(4):
                    mat[i+4*x][j+4*y] = nee
                    nee += 1

    for row in mat:
        print(*row)

    # for i in range(144):
    #     print(i,bin(i)[2::].zfill(8))
    
    # print()
    # print(checkrow(mat))
    # print(checkcol(mat))

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()