t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    a = set()
    b = set()

    for i in range(n):
        if s[i] == 'A': 
            a.add(i+1)
        else:
            b.add(i+1)

    if n in a and (1 in a or n-1 in a):
        print("Alice")

    else:
        if n in b:
            if len(b) > 1:
                print("Bob")
            else:
                print("Alice")
        else:
            print("Bob")