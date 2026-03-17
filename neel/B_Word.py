s = input()

upp = 0
low = 0

for i in s:
    if i.isupper():
        upp += 1
    else:
        low += 1

if upp > low:
    print(s.upper())
else:
    print(s.lower())

