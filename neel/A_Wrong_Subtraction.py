PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, k = map(int, input().split())

    res = n

    for i in range(k):
        if res%10 == 0:
            res = res//10
        else:
            res -=  1
    
    print(res)
    

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()