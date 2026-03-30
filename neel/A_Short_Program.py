def bee(x):
    return bin(x)[2::].zfill(10)

def dee(x):
    res = 0
    for i in range(10):
        res += (2**(9-i))*x[i]
    return res

xxor = [0]*10
aand = [1]*10
ooor = [0]*10

n = int(input())

for _ in range(n):
    op,b = input().split()
    b = int(b)
    x = bee(b)

    if op == '&':
        for i in range(10):
            if x[i] == '0':
                aand[i] = 0
                ooor[i] = 0
                xxor[i] = 0
    
    if op == '|':
        for i in range(10):
            if x[i] == '1':
                ooor[i] = 1
                aand[i] = 1
                xxor[i] = 0

    if op == '^':
        for i in range(10):
            if x[i] == '1':
                xxor[i] ^= 1
            else:
                xxor[i] ^= 0

print(3)
print('&',dee(aand))
print('|',dee(ooor))
print('^',dee(xxor))