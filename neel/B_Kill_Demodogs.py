t = int(input())

mod = 1000000007

for _ in range(t):
    n = int(input())
    m = n-1
    p1 = (n*(n+1)*(2*n+1))//6
    p2 = (m*(m+1)*(2*m+1))//6
    p3 = m*(m+1)//2

    ans = 2022*(p1+p2+p3)
    print(ans%mod)