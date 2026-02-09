def prime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True

n = int(input())

if prime(n):
    print(1)
elif n%2 == 0:
    print(2)
elif prime(n-2):
    print(2)
else:
    print(3)