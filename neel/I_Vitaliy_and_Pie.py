n = int(input())
s = input()

keys = {}

count = 0
for i in range(0, 2*n-2, 2):
    key = s[i]
    keys[key] = keys.get(key, 0) + 1
    
    door = s[i+1]
    if keys.get(door.lower(), 0) > 0:
        keys[door.lower()] -= 1

        if keys.get(door.lower(), 0) == 0:
            del keys[door.lower()]
    else:
        count += 1

print(count)