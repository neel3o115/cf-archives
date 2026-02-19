PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

nee = []

for i in range(60):
    nee.append(1+2**i)

def check(n):
    if n == 1:
        return True
    
    if n%2 == 0:
        return check(n//2)
    else:
        return False

def solve():
    n = int(input())

    if n < 5:
        print(-1)
        return

    if check(n):
        print(-1)
        return
    
    if check(n+1):
        print(-1)
        return
    

    for j in nee:
        if n+j > n^j and n+(n^j) > j and j+(n^j) > n:
            print(j)
            break

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()