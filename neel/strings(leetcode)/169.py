nums = [2,2,1,1,1,2,2]

def frequency_array(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq

freq = frequency_array(nums)

for k,v in freq.items():
    if v > len(nums)//2:
        print(k)
        break