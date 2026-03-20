
# time complexity = O(n)

# n = int(input())
# count = 0
# for i in range(1, n+1):
#      if n%i  == 0:
#           count += 1
# print(count)


n = int(input())
k = round(n**(0.5)+1)

nee = []
for i in range(1, k):
     if n%i  == 0:
          nee.append(i)
          if i != n/i:
               nee.append(n//i)
               
print(*sorted(nee))
