t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    for i in range(2, n+1): 
        if s[i-2] == '0':
            print(i-1, end=" ")
        else:
            print(n-i-2, end=" ")

    print()
