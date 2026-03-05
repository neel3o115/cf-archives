def fun(n):
    res = [1]*n

    for i in range(1,n,2):
        res[i] = ((i+1)//2)+1
    
    return res

t = int(input())

for _ in range(t):
    n = int(input())

    print(*fun(n))