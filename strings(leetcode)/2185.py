words = ["pay","attention","practice","attend"]
pref = "at"

count = 0
for i in range(len(words)):
    if words[i].startswith(pref):
        count += 1
print(count)