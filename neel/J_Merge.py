PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    for i in range(1,100):
        print(i, '+', i+1, '=', 2*i+1)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()