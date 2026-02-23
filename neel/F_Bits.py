t = int(input())

for _ in range(t):
    l, r = map(int, input().split())

    a = bin(l)[2::]
    b = bin(r)[2::]
    a = a[::-1]
    b = b[::-1]
    a = a+'0'*(len(b)-len(a))

    ans = 0

    # for i in range(l, r+1):
    #     s = bin(i)[2::]
    #     s = s[::-1]
    #     s = s+'0'*(len(s)-len(a))
    #     s = s[::-1]
    #     print(s, i) 

    for i in range(len(a)-1, -1, -1):
        if a[i] != b[i]:
            jee = True
            for j in range(i,-1,-1):
                if b[j] == '0':
                    jee = False
                    break
            if jee:
                ans += (2**(i+1))-1
                break
            else:
                ans += (2**(i))-1
                break

        elif a[i] == '1':
            ans += (2**(i))

    print(ans)