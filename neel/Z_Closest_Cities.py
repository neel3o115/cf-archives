PI = 3.14159265358979323846
E = 2.718281828459045
INF = 1000000000000000000
MOD1 = 1000000007
MOD2 = 998244353

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = [-1]*n
    b[0]=1
    b[n-1]=n-2
    for i in range(1,n-1):
        if(a[i]-a[i-1]<a[i+1]-a[i]):
            b[i]=i-1
        else:
            b[i]=i+1
    q=int(input())
    pre=[0]*n
    pre[0]=0

    for i in range(1,n):
        if b[i-1]==i:
            pre[i]=pre[i-1]+1
        else:
            pre[i]=pre[i-1]+a[i]-a[i-1]

    # print(pre)
    suff=[0]*n
    suff[n-1]=0


    for i in range(n-2,-1,-1):
        if b[i+1]==i:
            suff[i]=suff[i+1]+1
        else:
            suff[i]=suff[i+1]+a[i+1]-a[i]
            
    for i in range(q):
        u,v=map(int,input().split())
        u-=1
        v-=1
        if u<v:
            if u==0:
                print(pre[v])
            else:
                print(pre[v]-pre[u])
        else:
            # print(-1) 
            if u==n-1:
                print(suff[v])
            else:
                print(suff[v]-suff[u])
            


    

def main():
    t = 1
    t = int(input()) 
    for _ in range(t):
        solve()

main()