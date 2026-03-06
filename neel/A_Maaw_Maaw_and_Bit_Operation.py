PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [0]*30

    for i in range(n):
        s = bin(a[i])[2::]
        s = s[::-1]

        for j in range(len(s)):
            if s[j] == '1':
                b[j] = 1
    
    res = max(a)

    for i in range(30):
        if b[i] == 1:
            res += 2**(i)

    print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()