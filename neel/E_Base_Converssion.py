def rec(n):
    if n == 0:
        return
    
    rec(n//2)
    print(n%2,end='')

t = int(input())

for _ in range(t):
    n = int(input())

    if n == 0:
        print(0)
    else:
        rec(n)
        print()