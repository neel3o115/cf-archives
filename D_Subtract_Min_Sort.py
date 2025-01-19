t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    for i in range(n - 1):
        nee = min(arr[i], arr[i + 1])
        arr[i] -= nee
        arr[i + 1] -= nee
    
    if sorted(arr) == arr:
        print("YES")   
    else:
        print("NO")