def rev(lis):
    if len(lis) == 1:
        return lis
    if len(lis) == 2:
        a = lis[0]
        b = lis[1]
        c = [b,a]
        return c 
    else:
        c = lis.pop()
        d = [c, *rev(lis)]
        return d

lis = list(map(int,input().split()))
print(rev(lis))
