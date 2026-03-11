t = int(input())  

for _ in range(t):
    n = int(input())  
    nee = list(map(int, input().split())) 

    eve = [x for x in nee if x % 2 == 0]
    odd = [x for x in nee if x % 2 == 1]

    eve.sort(reverse=True)
    odd.sort(reverse=True)

    s = 0 
    p = 0

    for i in eve:
        s += i
        if s%2 == 0:
            p += 1
            while s%2 == 0:
                s //= 2

    for i in odd:
        s += i
        if s%2 == 0:
            p += 1
            while s%2 == 0:
                s //= 2

    print(p)  
