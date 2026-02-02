t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    yes = "YES"
    no = "NO"

    pos = True
    for i in range(n-1):
        if i%2==1:
            if a[i+1] > a[i]:
                pos = False
                break
    
    if pos:
        print(yes)
    else:
        print(no)
