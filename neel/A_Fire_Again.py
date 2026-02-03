import sys

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")

PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def dis(a,b,x,y):
    return abs(a-x)+abs(b-y)

def solve():
    n,m = map(int,input().split())

    x = [1,1,m,m]
    y = [1,n,1,n]
    d = [INF]*4

    q = int(input())

    ab = list(map(int,input().split()))

    for i in range(q):
        a,b = ab[2*i],ab[2*i+1]

        for j in range(4):
            d[j] = min(d[j],dis(a,b,x[j],y[j]))
    
    nee = max(d)

    for i in range(4):
        if d[i] == nee:
            print(x[i],y[i])
            break

def main():
    t = 1
    # t = int(input()) 
    for _ in range(t):
        solve()

main()

