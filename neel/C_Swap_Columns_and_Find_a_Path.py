t = int(input())

for _ in range(t):
    n = int(input())
    row1 = list(map(int, input().split()))
    row2 = list(map(int, input().split()))
    dic = dict(zip(row1, row2))

    summ = 0
    lis = []

    for key, value in dic.items():
        if key > value:
            summ += key
            lis.append(value)
        elif key <= value:
            summ += value
            lis.append(key)

    print(max(lis)+summ)

t = int(input())

for _ in range(t):
    n = int(input())
    row1 = list(map(int, input().split()))
    row2 = list(map(int, input().split()))

    matrix = [[row1[i], row2[i]] for i in range(n)]

    summ = 0
    lis = []

    for i in range(n):
        key, value = matrix[i]
        if key > value:
            summ += key
            lis.append(value)
        elif key <= value:
            summ += value
            lis.append(key)

    print(max(lis) + summ)
