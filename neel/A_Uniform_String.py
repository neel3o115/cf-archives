import math

t = int(input())

for _ in range(t):
    n, k = map(int, input().split()) 
    s = ""

    x = 97

    a = math.floor(n/k)
    
    for i in range(k):
        s += chr(x+i)*a

    while (len(s) < n):
        s += s[-1]
    
    print(s)