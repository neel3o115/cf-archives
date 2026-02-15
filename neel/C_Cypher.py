t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    
    two = []
    for i in range(n):
        x, y = map(str, input().split())
        two.append([int(x),y])

        for i in range(n):
            
            # for j in range():
            #     pass

        # for i in range(n):
        #     for char in y:
        #         if char == "D":
        #             arr[i] = (arr[i]-1)%10
        #         elif char == "U":
        #             arr[i] = (arr[i]+1)%10

    print(*arr)
    print(two)