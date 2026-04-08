n, q = map(int, input().split())
a = list(map(int, input().split()))

ans = []
found = False
def fun(idx, crr, x):
    global n, ans, a, found

    if found:
        return

    if crr == x: 
        # print(*ans)
        print(1)
        found = True
        return 

    if idx == n:
        return 

    ans.append(idx)
    fun(idx+1, crr+a[idx], x)
    ans.pop()
    fun(idx+1, crr, x)


qu = list(map(int, input().split()))
for i in range(q):
    ans = []
    found = False
    fun(0, 0, qu[i])
    if found == False:
        print(-1)


# print(*[i for i in range(1, 100001)])