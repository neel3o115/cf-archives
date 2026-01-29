t = int(input())

for _ in range(t):
    n = int(input())

    if (n < 2020):
        print("NO")
    else:
        a = n%2020
        b = n//2020

        if (a <= b):
            print("YES")
        else:
            print("NO")