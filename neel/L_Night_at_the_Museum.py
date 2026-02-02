s = input()
s = "a"+s
nee = "abcdefghijklmnopqrstuvwxyz"

count = 0
for i in range(len(s)-1):
    a = s[i]
    b = s[i+1]

    c = nee.index(a)
    d = nee.index(b)

    count += min(abs(c-d), 26-abs(c-d))

print(count)
