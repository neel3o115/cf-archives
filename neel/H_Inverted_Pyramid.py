def rec(l,n):
    if l == 0:
        return

    print((n-l)*" "+(1+2*(l-1))*"*")
    rec(l-1,n)

n = int(input())
rec(n,n)