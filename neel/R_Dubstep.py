s = input()
arr = s.split('WUB')

for i in arr:
    if i == '':
        arr.remove(i)
print(*arr)