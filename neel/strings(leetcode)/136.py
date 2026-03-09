nums = list(map(int, input().split()))

nee = nums[0]

for i in range(1,len(nums)):
    nee ^= nums[i]

print(nee)
