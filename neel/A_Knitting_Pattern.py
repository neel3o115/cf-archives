n,p = map(int,input().split())

if (n % p == 0):
    print(0)
else:
    print(2 * (((n - p) // 2) % p))