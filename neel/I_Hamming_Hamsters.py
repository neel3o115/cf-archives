nee = {}
n = 100

for i in range(n):
    for j in range(n):
        a = i^j

        if a.bit_count() in nee:
            nee[a.bit_count()].append((i,j))
        else:
            nee[a.bit_count()] = [(i,j)]

print(*nee[1])