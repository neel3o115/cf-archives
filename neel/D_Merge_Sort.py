def solve(n, k):
    res = [i for i in range(1, n+1)]

    if k%2 == 0:
        print(-1)
        return
    
    if k > 2*(n)-1:
        print(-1)
        return

    def helper(l, r, k):
        if k == 1:
            return 
        
        mid = (l+r)//2
        res[mid-1],res[mid] = res[mid],res[mid-1]

        if (k)%4 == 3:
            helper(l,mid,k//2)
            helper(mid,r,k//2)
        else:
            helper(l,mid,(k//2)-1)
            helper(mid,r,(k//2)+1)
    
    helper(0,n,k)

    print(*res)
    return

# t = int(input())

for _ in range(1):
    n, k = map(int, input().split())
    solve(n, k)