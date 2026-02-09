def rec(n):
    if n == 1:
        return 1
    if n%2 == 1:
        return 1+rec(3*n+1)
    else:
        return 1+rec(n//2)

n = int(input())
print(rec(n))