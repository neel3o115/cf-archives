n,q = map(int,input().split())
arr = list(map(int,input().split()))

prefix_arr = [0] * n
count = 0

for i in range(n):
    count += arr[i]
    prefix_arr[i] = count

for _ in range(q):
    a,b = map(int,input().split())
    if a == 1:
        print(prefix_arr[b-1])
    else:
        print(prefix_arr[b-1] - prefix_arr[a-2])

# checking