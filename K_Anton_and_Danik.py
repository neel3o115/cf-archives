n = int(input())
s = input()
d = s.count('D')
a = s.count('A')

if d > a:
    print("Danik")
elif a > d:
    print("Anton")
else:
    print("Friendship")