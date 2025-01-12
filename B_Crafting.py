def jee(arr, x):
    return [arr[i] - 1 if i != x else arr[i] + 1 for i in range(len(arr))]

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    count = 0
    nee = "YES"

    for i in range(n):
        if a[i] < b[i]:
            a = jee(a, i)
            count += 1
        
        if count == 2:
            nee = "NO"
            break

        # print(a)
    print(nee)


        




        

