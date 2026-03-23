PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort()
    m = n//2
    res = 0

    if a[m] == k:
        print(0)
        return
    elif a[m] < k:
        for i in range(m,n):
            if a[i]>=k:
                break
            else:
                res += k-a[i]
        
        print(res)
        return
    else:
        for i in range(m,-1,-1):
            if a[i]<=k:
                break
            else:
                res += a[i]-k
        
        print(res)

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()