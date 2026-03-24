t = int(input())

for _ in range(t):
    a, b = map(int, input().split()) 

    if a < b:
        a, b = b, a
    
    if (a == b):
        print(0)
    else:
        if (a%b == 0):
            print(1)
        else:
            print(2)