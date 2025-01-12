t = int(input())

for _ in range(t):
    n, a, b = map(int, input().split()) 

    nee = "YES"
    k = max(a, b)
    while k <= n and nee == "YES":
        if a == 1:
            if b == 2:
                nee = "NO"
            else:
                a += 1

        elif b == 1:
            if a == 2:
                nee = "NO"
            else:
                b += 1
        
        else:
            if (a+1 == b and a-1 == b):
                nee = "NO"
            else:
                if abs(a+1 - b) > abs(a-1 - b):
                    a -= 1
                else:
                    a += 1
            
            if (b+1 == a and b-1 == a):
                nee = "NO"
            else:
                if abs(b+1 - a) > abs(b-1 - a):
                    b -= 1
                else:
                    b += 1
            k = max(a, b)

    print(nee)
        