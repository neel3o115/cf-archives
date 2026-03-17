nums1 = [1,2]
nums2 = [3,4]

count = 0

def frequency_array(arr, lis):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += len((lis))
        else:
            freq[num] = len((lis))

    for num in lis:
        if num in freq:
            freq[num] += len(arr)
        else:
            freq[num] = len(arr)
    return freq

freq = frequency_array(nums1, nums2)

for k, v in freq.items():
    if v % 2 != 0:
        count ^= k

print(count)

