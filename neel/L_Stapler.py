def main():
    xl,yl,xr,yr = map(float,input().split())
    x1,y1,x2,y2 = map(float,input().split())

    if (x2 == x1) :
        slope = 0
    else:
        slope = (y2 - y1) / (x2 - x1)


    yy1 = slope * (xl - x1) + y1
    yy2 = slope * (xr - x1) + y1

    if (slope == 0):
        xx1 = x1
        xx2 = x2
    else:
        xx1 = (yl - y1) / slope + x1
        xx2 = (yr - y1) / slope + x1

    
    if (xx1 < xl and xx2 < xl and yy1 < yl and yy2 < yl):
        print("OK")
        return 
    if (xx1 > xr and xx2 > xr and yy1 > yr and yy2 > yr):
        print("OK")
        return 
    if (xx1 > xr and xx2 > xr and yy1 < yl and yy2 < yl):
        print("OK")
        return 
    if (xx1 < xl and xx2 < xl and yy1 > yr and yy2 > yr):
        print("OK")
        return 
    
    if (y1 < yl and y2 < yl):
        print("OK")
        return 
    if (y1 > yr and y2 > yr):
        print("OK")
        return 
    if (x1 < xl and x2 < xl):
        print("OK")
        return 
    if (x1 > xr and x2 > xr):
        print("OK")
        return 

    print("STOP")
    return


t = int(input())
while (t):
    main()
    t -= 1