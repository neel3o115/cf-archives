n,m = map(int,input().split())

x = []
y = []

ux = []
uy = []

arr1 = []
arr2 = []
for i in range(n):
    a,b = map(int,input().split())
    # arr1.append([a,b])
    x.append(a)
    ux.append(b)


for j in range(m):
    e,f = map(int,input().split())
    # arr2.append([e,f])
    y.append(e)
    uy.append(f)



# while len(x) > 0 and len(y) > 0:
#     tx = []
#     ty = []
#     for i in range(len(x)):
#             p, o = x[i], ux[i]*z
#             tx.append([p,o])

#     for i in range(len(y)):
#             q, r = y[i], uy[i]*z
#             ty.append([r,q])
    # for i in tx:
    #     if i in ty:
    #          cout+=1
    #          x.remove(i[0])
    #          y.remove(i[1])
#     z+=1
# print(cout)

z = 1
cout = 0


while z<3:
    tx = []
    ty = []
    for i in range(len(x)):
            p, o = x[i], ux[i]*z
            tx.append([p,o])

    for i in range(len(y)):
            q, r = y[i], uy[i]*z
            ty.append([r,q])
    for i in tx:
        if i in ty:
            cout+=1
            x.remove(i[0])
            y.remove(i[1])
                 
    z+=1
[]
    


# print(tx)
# print(ty)

    
