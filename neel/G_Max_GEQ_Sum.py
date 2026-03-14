t = int(input())

for i in range(t):
    n = int(input())
    l = list(map(int,input().split()))

    curr = l[0]
    # maxa = l[0]


    right = [0] * n
    left = [0] * n

    for i in range(1,n):
        if l[i] >= 0:
            if curr + l[i] > l[i]:
                right[i] = 1
                # print("NO")
                # break
            else:
                curr = l[i]
        else:
            curr += l[i]


    c = l[-1]
    for i in range(n-2,-1,-1):
        if l[i] >= 0:
            if curr + l[i] > l[i]:
                left[i] = 1
                # print("NO")
                # break
            else:
                curr = l[i]   ,m nb 
        else:
            curr += l[i]

    for i in range(n):
        if right[i] + left[i] == 2:
              
            print("NO")
            break
    else:
        print("YES")
            
            