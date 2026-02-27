t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split()) 

    if (a+b+c)%3 != 0:
        print("NO")
    
    else:
        if b > (a+b+c)//3:
            print("NO")
        else:
            print("YES")