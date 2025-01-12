nums = [0,1,2,2,3,0,4,2]
val = 2
nee = 0

for i in range(len(nums)):
    if nums[i-nee] == val:
        nums.remove(nums[i-nee])
        nums.append("_")
        nee += 1
    else:
        print(nums[i])

print(nums[:len(nums)-nee])
print(nums)