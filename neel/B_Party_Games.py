PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())

    if n%4 == 0:
        print('Fluttershy')
        return

    if n%4 == 1:
        print('Fluttershy')
        return

    if n%4 == 2:
        print('Pinkie Pie')
        return

    if n%4 == 3:
        print('Pinkie Pie')
        return

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()