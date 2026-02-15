import math
 
n,q = map(int,input().split())
a = [0]*n
B = math.ceil(math.sqrt(n))

# print(len(a))
 
b = [0]*(math.ceil(n/B)+1)
for i in range(n):
    b[i//B] += a[i]

flip = False
 
for i in range(q):
    oxyc = list(map(int,input().split()))
    o = oxyc[0]
 
    if o == 1:
        x,y,c = oxyc[1],oxyc[2],oxyc[3]
        if flip:
            x,y = n-y+1,n-x+1
        
        x -= 1
        y -= 1
        
        st = x//B
        nd = y//B

        print(x,st)
        print(y,st)

        if st%B != 0:
            for i in range(B*st,B*st+B):
                if i < n:
                    a[i] = b[i//B]
            
            for i in range(B*st,B*st+B):
                if i < n:
                    if i >= x:
                        a[i] = c
        
        if nd%B != 0:
            for i in range(B*nd,B*nd+B):
                if i < n:
                    a[i] = b[i//B]
            
            for i in range(B*nd,B*nd+B):
                if i < n:
                    if i <= y:
                        a[i] = c

        b[st] = 0
        b[nd] = 0

        while (x < y-B):
            if (x%B == 0):
                b[x//B] = c
                x += B

    else:
        flip = not flip 

res = [0]*n

print(B)
print(*a)
print(b)


# for i in range(n):
#     res[i] = a[i]

# if not flip:
#     print(*res)
# else:
#     res = reversed(res)
#     print(*res)
