n = int(input())
a = int(input())
b = int(input())

for x in range( n//a+1):
    if (n-a*x)%b==0:
        print("YES")
        print(x,(n-a*x)//b)
        break
else:
    print("NO")