t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    if sum(arr)%3 == 0 or all(x == arr[0] for x in arr):
        print("YES")
    else:
        print("NO")