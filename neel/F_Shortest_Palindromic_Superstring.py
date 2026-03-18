def merge(a, b):
    nee = 0
    for k in range(1, min(len(a), len(b))+1):
        if a[-k:] == b[:k]:
            nee = k

    return a+b[nee:]

def fun(a, b):
    c = a[::-1]
    d = a[::-1]

    if a in b:        
        return [b,b]
    elif b in a:    
        return [a,a]
    elif b[::-1] in a:
        return [a,a]
    elif a[::-1] in b:     
        return [b,b]
    
    nee = merge(a, b)
    jee = merge(b, a)

    return (nee, jee)


def solve(res):
    l = []
    for i in res:
        l.append(i)
    
    n = len(l)
    ans = float('inf')
    
    for k in range(n-1,-1,-1):
        # odd
        mid = l[k]
        left = k-1
        right = k+1

        # print(res,mid)


        possible = True

        uu = 0

        c = 1

        while True:
            left_char = "" if left < 0 else res[left]
            right_char = "" if right >= n else res[right]

            if left_char == right_char and left_char != "":
                left -= 1
                right += 1
            elif left_char != right_char and left_char and right_char:
                possible = False
                break
            elif left_char == "" and right_char == "":
                # possible = False
                break
            else:
                left -= 1
                right += 1
                uu += 1
            
        if (possible):
            ans = min(ans,n + uu)
        

        #even
        mid = l[k]
        if k == 0 or l[k] != l[k-1]:
            continue

        left = k - 2
        right = k + 1

        # print(res,mid)


        possible = True

        uu = 0

        while True:
            left_char = "" if left < 0 else res[left]
            right_char = "" if right >= n else res[right]

            if left_char == right_char and left_char != "":
                left -= 1
                right += 1
            elif left_char != right_char and left_char and right_char:
                possible = False
                break
            elif left_char == "" and right_char == "":
                # possible = False
                break
            else:
                left -= 1
                right += 1
                uu += 1
            
        if (possible):
            ans = min(ans,n + uu)
    
    return ans

T = int(input())
while T:
    s,t = input().split()

    # res = s + t
    res = fun(s,t)

    print(res)

    res1 = res[0]
    res2 = res[1]

    # l = []
    # for i in res:
    #     l.append(i)
    
    # n = len(l)
    # ans = float('inf')

    print(min(solve(res1),solve(res2)))
    
    # for k in range(n-1,-1,-1):
    #     # odd
    #     mid = l[k]
    #     left = k-1
    #     right = k+1

    #     # print(res,mid)


    #     possible = True

    #     uu = 0

    #     c = 1

    #     while True:
    #         left_char = "" if left < 0 else res[left]
    #         right_char = "" if right >= n else res[right]

    #         if left_char == right_char and left_char != "":
    #             left -= 1
    #             right += 1
    #         elif left_char != right_char and left_char and right_char:
    #             possible = False
    #             break
    #         elif left_char == "" and right_char == "":
    #             # possible = False
    #             break
    #         else:
    #             left -= 1
    #             right += 1
    #             uu += 1
            
    #     if (possible):
    #         ans = min(ans,n + uu)
    


    T -= 1











