PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, k = map(int, input().split())
    s = list(input())
    ss = []
    a = []
    b = []

    a.append(s[0])
    b.append(1)

    for i in range(1,n):
        if s[i] == a[-1]:
            b[-1] += 1
        else:
            a.append(s[i])
            b.append(1)
    
    if len(a) == 1:
        print(k*n-1)
        return
    
    for i in range(1, len(a)-1):
        if a[i] == 'I':
            if b[i+1]:
                b[i] = max(b[i+1], b[i-1])

    print(*a)
    print(*b)
    print()

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()