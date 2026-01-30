a, b, n = map(int, input().split())
x = a

for i in range(10):
    if (a*10+i)%b == 0:
        a = a*10+i
        break
    
if a == x:
    print(-1)

else:
    print(str(a)+"0"*(n-1))