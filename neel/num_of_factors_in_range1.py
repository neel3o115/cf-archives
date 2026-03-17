n = int(input())

div_count = [0] * (n + 1)

for i in range(1, n + 1):
    for j in range(i, n + 1, i):
        div_count[j] += i

for i in range(1, n + 1):
    print(div_count[i])

# time complexity = n/1 + n/2 + n/3 ... n/n 
#                 = n(ln(n)) (approx)