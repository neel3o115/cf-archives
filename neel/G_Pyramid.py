def rec(l,n):
    if l == 0:
        return

    rec(l-1,n)
    print((n-l)*" "+(1+2*(l-1))*"*")

n = int(input())
rec(n,n)