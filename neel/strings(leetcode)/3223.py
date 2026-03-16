s = "abaacbcbb"

def frequency_array(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq

freq = frequency_array(s)

count = 0
for i in freq.values():
    if i % 2 == 0:
        count += 2
    else:
        count += 1

print(count)