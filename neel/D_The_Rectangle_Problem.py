x1,y1,x2,y2 = map(int,input().split())
h = abs(y1-y2)
w = abs(x1-x2)


if y1%2 == 0 and y2%2 == 1:
    res = (h//2+1)*(w) 

    print(res)

elif y1%2 == 1 and y2%2 == 0:
    res = (h//2+1)*(w) 

    print(res)

else:
    res = (h//2+1)*(w//2+1) + (h//2)*(w//2) 

    print(res)