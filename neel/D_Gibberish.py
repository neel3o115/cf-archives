n = int(input())

arr = [0 for i in range(n)]

intTochar = {}

for i in range(26):
    intTochar[i] = chr(ord('a') + i)

 
 

def alloter(passedArr):
    for i in range(len(passedArr)):
        passedArr[i] = (i % 26)
    
    return passedArr

arr = alloter(arr)

print(arr)
