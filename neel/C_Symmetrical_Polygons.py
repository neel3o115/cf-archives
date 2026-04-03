import sys
from collections import Counter
from itertools import accumulate

input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    
    fr = Counter(a)
    
    s1 = 0
    s2 = 0
    nee = []
    cnt = 0
    
    for key, val in fr.items():
        if val % 2 == 0:
            cnt += val
        s1 += key * (val // 2)
        s2 += key * (val // 2)
        fr[key] = val % 2
        if fr[key]:
            nee.append(key)
    
    nee.sort()
    nee.reverse()
    
    s3 = 0
    s4 = 0
    
    if len(nee) == 0:
        if cnt == 2:
            print(0)
        else:
            print(s1 + s2)
    
    elif len(nee) == 1:
        s3 = nee[0]
        if s1 + s2 > s3:
            print(s1 + s2 + s3 + s4)
        else:
            if cnt == 2:
                print(0)
            else:
                print(s1 + s2)
    
    else:  # len(nee) > 1
        s3 = nee[0]
        s4 = nee[1]
        if s3 < s4:
            s3, s4 = s4, s3
        
        if (s1 + s2 + s3 > s4) and (s1 + s2 + s4 > s3):
            print(s1 + s2 + s3 + s4)
        elif s1 + s2 > s3:
            print(s1 + s2 + s3)
        elif s1 + s2 > s4:
            print(s1 + s2 + s4)
        else:
            print(0)


t = int(input())
for _ in range(t):
    solve()
