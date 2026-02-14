t = int(input())

def fun(x,n,m):
    if n == 1:
        return 1
    if n%2 == 0:
        return ((1+pow(x,n//2,m))*fun(x,n//2,m))%m
    else:
        return ((1+pow(x,n//2,m))*fun(x,n//2,m)+(pow(x,n-1,m)))%m

for _ in range(t):
    x,n,m = map(int,input().split())

    print(fun(x,n,m))

