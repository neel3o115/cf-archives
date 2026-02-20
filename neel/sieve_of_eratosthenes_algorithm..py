n = int(input())

divisors = [0] * (n + 1)

for i in range(1, n + 1):
    for j in range(i, n + 1, i):
        divisors[j] += 1


print(divisors)