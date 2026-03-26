PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,k = map(int,input().split())
    a = list(map(int, input().split()))

    if sum(a)%2 == 1:
        print("YES")
        return
    else:
        if (n*k)%2 == 0:
            print("YES")
            return
    
    print("NO")

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()