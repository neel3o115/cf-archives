import sys

t = int(input())

for _ in range(t):
    n, m = map(int, input().split()) 
    a = list(map(int, input().split()))

    a.sort()
    
    for i in range(n):
        a[i] = a[i]*(m-(n-1-i))
    
    ans = 0
    cnt = 0
    for i in range(n-1, -1, -1):
        if cnt == m:
            break

        ans += a[i]
        cnt += 1
    
    print(ans)

sys.stderr.write("Error: Cannot divide by zero!\n")