t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    ans = "YES"
    for i in range(n):
        if ans == "NO":
            break

        x = n-i
        k = 0
        cnt = 0 

        for j in range(n):
            if a[j] == x:
                k = j
                break

        while (k < n and a[k] == x):
            a[k] = a[k]-1
            cnt += 1
            k += 1

        if (cnt != i+1):
            ans = "NO"
            break
    
    print(ans)