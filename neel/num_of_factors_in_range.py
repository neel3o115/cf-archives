def num_of_fac(n):
    k = round(n**(0.5)+1)
    count = 0
    for i in range(1, k):
        if n%i  == 0:
            count += 1
            if i != n/i:
                count += 1
    return count

num = int(input())

for i in range(1,num+1):
    print(num_of_fac(i))
    
# time complexity = sqrt(1) + sqrt(2) + sqrt(3) + sqrt(4)...sqrt(n)
#                 = 2/3 * ( (n ** 3/2) + 1)
def frequency_array(arr):
    freq = {}
    for num in arr:
        if num in freq:
            freq[num] += 1
        else:
            freq[num] = 1
    return freq