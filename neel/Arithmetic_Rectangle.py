import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]

    ans = 1
    ans = max(ans, n)
    ans = max(ans, m)


    if n >= 2:
        for i in range(n - 1):
            cur = 1
            for j in range(1, m):
                if a[i][j] - a[i][j-1] == a[i+1][j] - a[i+1][j-1]:
                    cur += 1
                else:
                    cur = 1
                ans = max(ans, 2 * cur)


    if m >= 2:
        for j in range(m - 1):
            cur = 1
            for i in range(1, n):
                if a[i][j] - a[i-1][j] == a[i][j+1] - a[i-1][j+1]:
                    cur += 1
                else:
                    cur = 1
                ans = max(ans, 2 * cur)

    if n < 3 or m < 3:
        print(ans)
        continue

    good = [[0]*m for _ in range(n)]

    for i in range(1, n-1):
        for j in range(1, m-1):
            if (
                a[i][j] - a[i][j-1] == a[i][j+1] - a[i][j] and
                a[i-1][j] - a[i-1][j-1] == a[i-1][j+1] - a[i-1][j] and
                a[i+1][j] - a[i+1][j-1] == a[i+1][j+1] - a[i+1][j] and
                a[i][j] - a[i-1][j] == a[i+1][j] - a[i][j] and
                a[i][j-1] - a[i-1][j-1] == a[i+1][j-1] - a[i][j-1] and
                a[i][j+1] - a[i-1][j+1] == a[i+1][j+1] - a[i][j+1]
            ):
                good[i][j] = 1

    height = [0] * m
    for i in range(n):
        stack = []
        for j in range(m):
            if good[i][j]:
                height[j] += 1
            else:
                height[j] = 0

        left = [-1] * m
        right = [m] * m

        for j in range(m):
            while stack and height[stack[-1]] >= height[j]:
                stack.pop()
            left[j] = stack[-1] if stack else -1
            stack.append(j)

        stack.clear()
        for j in range(m-1, -1, -1):
            while stack and height[stack[-1]] >= height[j]:
                stack.pop()
            right[j] = stack[-1] if stack else m
            stack.append(j)

        for j in range(m):
            if height[j]:
                H = height[j] + 2
                W = (right[j] - left[j] - 1) + 2
                ans = max(ans, H * W)

    print(ans)