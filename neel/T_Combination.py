def nCr(n,r):
    if r == 0:
        return 1
    return (n-r+1) * (nCr(n,r-1)) // r 

n,r = map(int,input().split())
print(nCr(n,r))