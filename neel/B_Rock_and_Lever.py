PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def msb(n):
    return len(bin(n)[2::])

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    fr = {}

    for i in range(n):
        x = msb(a[i])
        fr[x] = fr.get(x,0)+1
    
    res = 0

    for i in fr:
        x = fr[i]
        res += x*(x-1)//2
    
    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()