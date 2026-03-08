n = int(input())

a = []

for i in range(n):
    temp = set(map(int, input().split()))
    a.append(temp)

for i in range(0, 1000):
    vis = [0]*n

    s = str(i)
    print(s)

    
