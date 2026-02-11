MOD = 1000000007

N = 1003

fac = [0]*N 
inv = [0]*N

def power(a,b):
    res = 1

    while (b):
        if (b & 1):
            res = res*a % MOD
        a = a*a % MOD
        b >>= 1

    return res

fac[0] = 1
for i in range(1,N):
    fac[i] = (fac[i-1]*i) % MOD

inv[N-1] = power(fac[N-1],MOD-2)
for i in range(N-2,-1,-1):
    inv[i] = (inv[i+1]*(i+1)) % MOD

def pc(n):
    return n.bit_count()

def nCr(n, r):
    if r < 0 or r > n:
        return 0
    return fac[n] * inv[r] % MOD * inv[n-r] % MOD

def fun(n):
    x = n
    y = 0

    while x != 1:
        x = pc(x)
        y += 1

    return y

mp = [[] for i in range(5)]

def nee(s,x):
    n = len(s)
    ans = nCr(n,x)
    one = 0

    for i in range(n):
        if one == x:
            break
        if s[i] == '1':
            one += 1
        else:
            rem = n-1-i
            ans = (ans-nCr(rem,x-(one+1)))%MOD

    return ans

s = input()
n = int(s,2)
k = int(input())

for i in range(1,1001):
    mp[fun(i)].append(i)

if k == 0:
    print(1)
elif k > 5:
    print(0)
else:
    ans = 0

    for i in range(len(mp[k-1])):
        ans = (ans+nee(s,mp[k-1][i]))%MOD

    if k == 1:
        ans -= 1

    print(ans)

