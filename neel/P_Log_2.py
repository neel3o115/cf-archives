def rec(n):
    if n == 1:
        return 0
    return 1+rec(n//2)

n = int(input())
print(rec(n))