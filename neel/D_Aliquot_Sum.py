PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

N = 1000006
div = [0]*N

for i in range(1,N):
    for j in range(2*i,N,i):
        div[j] += i

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    for i in range(n):
        if div[a[i]] > a[i]:
            print('abundant')
        elif div[a[i]] < a[i]:
            print('deficient')
        elif div[a[i]] == a[i]:
            print('perfect')

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()