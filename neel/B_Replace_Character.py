def count_elements(lst):
    res = {}
    for val in lst:
        res[val] = res.get(val, 0) + 1
    return res

for _ in range(int(input())):
    n = int(input())
    s = input()

    freq = count_elements(s)

    sorted_freq = sorted(freq.items(), key=lambda x: x[1])

    min_char = sorted_freq[0][0]
    max_char = sorted_freq[-1][0]

    result = s.replace(min_char, max_char, 1)

    print(result)