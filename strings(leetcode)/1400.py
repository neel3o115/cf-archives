s = input()
k = int(input())

def frequency_array(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq

freq = frequency_array(s)

eve = 0
odd = 0

for value in sorted(freq.values()):
    if value % 2 == 0:
        eve += 1
    else:  
        odd += 1

# print(freq)
# print(eve, odd)

if eve > k and odd%k == 0:
    print("true")
elif odd <= k and len(s) >= k:
    print("true")
elif odd > k and len(freq) < k:
    print("true")
else:
    print("false")

# print(eve, odd)
