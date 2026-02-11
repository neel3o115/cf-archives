PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

n = 5000006
spf = [i for i in range(n)]

for i in range(2,n):
    if spf[i] == i:
        for j in range(i*i,n,i):
            if spf[j] == j:
                spf[j] = i
    
fac = [0]*n

for i in range(2,n):
    if spf[i] == i:
        fac[i] = 1
    else:
        fac[i] = 1+fac[i//spf[i]]

ps = [0]*n
for i in range(1,n):
    ps[i] = ps[i-1]+fac[i]

def solve():
    a,b = map(int,input().split())
    print(ps[a]-ps[b])

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()