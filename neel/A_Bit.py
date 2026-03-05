n = int(input())

x = 0
c = 0
for i in range(n):
    s = input()

    if s == '++X':
        x += 1+c
        c = 0

    if s == 'X++':
        c += 1
    
    if s == '--X':
        x += -1+c
        c = 0

    if s == 'X--':
        c -= 1

print(x+c)
