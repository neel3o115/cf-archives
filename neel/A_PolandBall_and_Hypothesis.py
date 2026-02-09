PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def isPrime(x):
    for i in range(2,x):
        if x%i == 0:
            return False
    
    return True

def solve():
    n = int(input())

    for m in range(1, 1001):
        x = n*m + 1 

        if not isPrime(x):
            print(m)
            return


def main():
    t = 1
    # t = int(input()) ``
    for _ in range(t):
        solve()

main()