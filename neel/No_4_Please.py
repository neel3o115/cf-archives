PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    fr = [0]*4

    for num in a:
        fr[num] += 1

    res = 0

    if fr[2] > 0:
        res += fr[2]-1
    res += min(fr[1], fr[3])

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()