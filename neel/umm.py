def kadane(a):
    mx = float('-inf')
    sm = 0

    for i in range(len(a)):
        sm += a[i]
        mx = max(mx, sm)

        if sm < 0:
            sm = 0

        if mx < 0:
            mx = 0
    return mx

def maxSub(a):
    mx = float('-inf')
    sm = 0

    for i in range(len(a)):
        if sm == 0:
            srt = i
        sm += a[i]

        if sm > mx:
            mx = sm
            end = i

        if sm < 0:
            sm = 0

        if mx < 0:
            mx = 0
    return a[srt:end+1]


a = list(map(int, input().split()))

print(kadane(a))
print(maxSub(a))