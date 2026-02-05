def nC1(n):
    return n

def nC2(n):
    return nC1(n)*(n-1)//2

def nC3(n):
    return nC2(n)*(n-2)//3

def nC4(n):
    return nC3(n)*(n-3)//4

def nC5(n):
    return nC4(n)*(n-4)//5

n = int(input())

a = 0
b = 0

if n > 0:
    a += nC1(n)*1

if n > 1:
    a += nC2(n)*4

if n > 2:
    a += nC3(n)*6

if n > 3:
    a += nC4(n)*4

if n > 4:
    a += nC5(n)*1


if n > 0:
    b += nC1(n)*1

if n > 1:
    b += nC2(n)*2

if n > 2:
    b += nC3(n)*1

print(a*b)