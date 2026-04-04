n = int(input())
a = list(map(int, input().split()))

N = max(a)

count = [0]*(N+1)
f = [0]*(N+1)
is_prime = [True]*(N+1)

is_prime[0] = False
is_prime[1] = False

for x in a:
    count[x] += 1

for i in range(2, N+1):
    if is_prime[i]:
        for j in range(i,N+1,i):
            f[i] += count[j]
            if j>i:
                is_prime[j]=False

for i in range(1, N+1):
    f[i] += f[i-1]

m = int(input())
for _ in range(m):
    l, r = map(int,input().split())
    
    if l > N:
        print(0)
    else:
        r = min(r, N)
        print(f[r]-f[l-1])