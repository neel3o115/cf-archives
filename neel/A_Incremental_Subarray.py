t = int(input())
for i in range(t):
    n,m = map(int,input().split())
    l = list(map(int,input().split()))
 
    if (m >= 2):
        if l[0] == 1 and l[1] == 1:
            print(1)
        else:
            if l == sorted(l):
                print(n-max(l)+1)
            else:
                print(1)
    else:
        print(n-max(l)+1)