A = [1,3,2,4] 
B = [3,1,2,4]
C = []
count = 0
aaa = set()
bbb = set()

for i in range(len(A)):
    aaa.add(A[i])
    bbb.add(B[i])
    ccc = (aaa.intersection(bbb))
    C.append(len(ccc))

print(C)