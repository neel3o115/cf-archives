def rec(a,i,j):
    if i==j:
        return "YES"
    
    if i+1==j:
        if a[i] == a[j]:
            return "YES"
        return "NO"

    if a[i] == a[j]:
        return rec(a,i+1,j-1)
    
    return "NO"


n = int(input())
a = list(map(int,input().split()))

print(rec(a,0,n-1))