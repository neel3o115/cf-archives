main = input()
zero = input()
one = input()
two = input()
three = input()
four = input()
five = input()
six = input()
seven = input()
eight = input()
nine = input()

d = {zero: 0, one: 1, two: 2, three: 3, four: 4, five: 5, six: 6, seven: 7, eight: 8, nine: 9}
for i in range(0, 80, 10):
    print(d[main[i:i+10]], end="")