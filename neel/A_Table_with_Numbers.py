PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,h,l = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    for i in range(n-1,-1,-1):
        if a[i] > max(h,l):
            a.pop()
        else:
            break

    if len(a) == 0:
        print(0)
        return 
    
    x = 0

    for i in range(len(a)):
        if a[i] <= min(h,l):
            x += 1
    
    if x >= len(a)//2:
        print(len(a)//2)
        return

    if x < len(a)//2:
        print(x)
        return
    

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()