def rec(a,i): 
    if i < 0:
        return
    
    if i%2 == 0:
        print(a[i],end=' ')
        rec(a,i-2)
    else:
        rec(a,i-1)

n = int(input())
a = list(map(int,input().split()))

rec(a,n-1)
