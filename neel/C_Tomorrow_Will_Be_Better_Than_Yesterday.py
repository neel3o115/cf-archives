import math
import portion as Interval

u = Interval.closedopen(0, 2*math.pi)
interval = Interval.closedopen(0, 2*math.pi)

def fun1 (x1, y1, x2, y2):
    if y1 == y2:
        return math.pi/2

    return math.atan((x2-x1)/(y2-y1))

def fun2 (x1, y1, x2, y2, t):
    global interval, u

    m = Interval.openclosed(t, t+math.pi)

    if (y1-y2) * math.cos(t) > (x2-x1) * math.sin(t):
        interval = interval & m
    else:
        interval = interval & (u-m)

n = int(input())
cors = []

for i in range(n):
    p = list(map(int, input().split()))
    cors.append(p)

for i in range(n-1):
    x1, y1 = cors[i]
    x2, y2 = cors[i+1]

    fun2(x1, y1, x2, y2, fun1(x1, y1, x2, y2))

if interval.empty:
    print("NO")
else:
    print("YES")
    # print(math.cos(), math.sin())
    # print(-math.sin(), math.cos())

print(interval)