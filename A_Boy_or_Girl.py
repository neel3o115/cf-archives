s = input()

def frequency_array(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq

if len(frequency_array(s)) % 2 == 0:
    print('CHAT WITH HER!')
else:
    print('IGNORE HIM!')