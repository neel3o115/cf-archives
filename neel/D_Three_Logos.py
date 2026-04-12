a = list(map(int, input().split()))
xy = []

for i in range(3):
    hw = [a[2*i],a[2*i+1]]
    hw.sort(reverse=True)
    xy.append(hw + [i])

xy.sort(reverse=True)

x0, y0, c0 = xy[0][0], xy[0][1], xy[0][2]
x1, y1, c1 = xy[1][0], xy[1][1], xy[1][2]
x2, y2, c2 = xy[2][0], xy[2][1], xy[2][2]

clr = {0: 'A', 1: 'B', 2: 'C'}

if (x0 == x1 == x2 and x0 == y0+y1+y2):
    print(x0)
    for i in range(y0):
        print(clr[c0]*x0) 

    for i in range(y1):
        print(clr[c1]*x0) 
        
    for i in range(y2):
        print(clr[c2]*x0) 

elif (x0 == x1+x2 == y0+y1 and y1 == y2):
    print(x0)
    for i in range(y0):
        print(clr[c0]*x0)   
    
    for i in range(y1):
        print(clr[c1]*x1+clr[c2]*x2)

elif (x0 == x1+y2 == y0+y1 and y1 == x2):
    print(x0)
    for i in range(y0):
        print(clr[c0]*x0)  
    
    for i in range(y1):
        print(clr[c1]*x1+clr[c2]*y2)

elif (x0 == y1+y2 == x1+y0 and x1 == x2):
    print(x0)
    for i in range(y0):
        print(clr[c0]*x0)   
    
    for i in range(x1):
        print(clr[c1]*y1+clr[c2]*y2)
    
else:
    print(-1)