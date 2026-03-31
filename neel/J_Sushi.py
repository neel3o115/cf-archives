import sys
sys.setrecursionlimit(100000) 

def rec(a, b, c, n, dp):
    if n == 1:
        return a+b+c

    


n = int(input())
dp = [[[0 for i in range(n+1)] for j in range(n+1)] for k in range(n+1)]
v = list(map(int, input().split()))
s = [0,0,0]

for i in v:
    s[i-1] += 1

print(rec(s[0],s[1],s[2],n,dp))
# print(rec(1,1,0,n,dp))