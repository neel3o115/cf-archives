n = int(input())

def rec(n):
    if n == 1:
        print(n)
        return
    print(n,end=" ")
    rec(n-1)

rec(n)