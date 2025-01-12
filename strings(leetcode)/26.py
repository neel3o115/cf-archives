nums = list(map(int, input().split()))

nee = [nums[0]]
count = 0

for i in range(1, len(nums)):
    if nums[i] in nee:
        nums[i] = 111
        count += 1
    else:
        nee.append(nums[i])
nums.sort()

print(nums[:len(nums)-count])


        
  