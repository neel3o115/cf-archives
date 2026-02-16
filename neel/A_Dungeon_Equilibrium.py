PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    fr = {}

    for i in range(n):
        fr[a[i]] = fr.get(a[i],0)+1
    
    ans = 0

    for key in fr:
        x = key
        y = fr[key]

        if x > y: 
            ans += y
        else:
            ans += y-x
    
    # print(fr)
    print(ans)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()