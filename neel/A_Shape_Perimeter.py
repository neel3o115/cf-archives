t = int(input())
 
for _ in range(t):
    n, m = map(int, input().split()) 
 
    nee = 0
    for i in range(n):
        x, y = map(int, input().split())
 
        nee += 4*m
 
        if i != 0:
            nee -= 2*((m - y) + (m - x))
    
    print(nee)