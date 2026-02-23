t = int(input())

for _ in range(t): 
    n = int(input())
    a = list(map(int, input().split()))

    ans = -1

    for i in range(1, 1025):
        st = set(a)

        for j in range(n):
            if (a[j] in st) and ((a[j]^i) in st):
                st.remove(a[j])
                st.remove(a[j]^i)
        
        if (len(st) == 0):
            ans = i
            break
    
    print(ans)
    



    