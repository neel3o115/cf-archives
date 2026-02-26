s1 = input()
s2 = input()
s3 = input()

if sorted(s3) == sorted(s1+s2):
    print("YES")
else:
    print("NO")