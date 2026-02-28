t = int(input())

for _ in range(t):
    n = int(input())
    b = bin(n)[2::]

    print(2**(len(b)-1)-1)