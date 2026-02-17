PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    nee=a[n-1]-a[0]

    if a[0]==a[n-1]:
        print(n*(n-1))
        return

    fr ={}
    for i in range(n):
        fr[a[i]] = fr.get(a[i],0)+1
    # print(fr)
    res=0

    zee=set(a)
    for i in zee:
        x = fr[i]
        y = fr.get(i-nee,0)
        # print(i,x,i-nee,y)
        res+=x*y*2

    print(res)

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()