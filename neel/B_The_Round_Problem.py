PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, m = map(int, input().split())

    x = n
    two = 0
    five = 0

    while x%2 == 0:
        two += 1
        x //= 2

    while x%5 == 0:
        five += 1
        x //= 5

    k = 1

    while two<five and k*2 <= m:
        k *= 2
        two += 1

    while five<two and k*5 <= m:
        k *= 5
        five += 1

    while k*10 <= m:
        k *= 10

    k *= (m//k)

    print(n*k)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()