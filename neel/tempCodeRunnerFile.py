n = int(input())
if n%2 == 0:
    print(n//2)
    k = n//2
    print("2 "*k)
else:
    print((n-3)//2+1)
    k = (n-3)//2
    print("3","2 "*k)