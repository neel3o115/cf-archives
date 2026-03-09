PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split())) 
    b = [a[0]]
    res = 0

    if a.count(a[0]) == n:
        print((n-1)*a[0])
        return 
    
    c = []

    for i in range(1, n):
        c.append(max(a[i],a[i-1]))
    c.append(max(a[0],a[-1]))

    c.sort()
    c.pop()

    print(res+sum(c))
        
def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()