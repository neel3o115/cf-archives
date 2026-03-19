PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n, k = map(int, input().split())
    q = list(map(int, input().split()))
    r = list(map(int, input().split()))
    q.sort()
    r.sort()
    
    j = 0
    count = 0
    for i in range(n-1,-1,-1):
        if j < n and (q[i]+1)*(r[j]+1) <= k+1:
            count += 1
            j += 1
    
    print(count)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()