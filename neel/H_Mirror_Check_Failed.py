def palindrome(s):
    if s == s[::-1]:
        return True
    return False

t = int(input()) 

for _ in range(t):
    s = input()

    if not palindrome(s):
        print(len(s))
    else:
        if s.count(s[0]) == len(s):
            print(0)
        else:
            print(len(s)-1)