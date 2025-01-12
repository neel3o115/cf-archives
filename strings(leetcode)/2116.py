def canBeValid(s, locked):
    if len(s) % 2 != 0:
        return False
    
    n = len(s)
    o = 0
    c = 0

    for i in range(n):
        if locked[i] == "0" or s[i] == "(":
            o += 1
        else:
            o -= 1
        
        if o < 0:
            return False
    
    for i in range(n - 1, -1, -1):
        if locked[i] == "0" or s[i] == ")":
            c += 1
        else:
            c -= 1
        
        if c < 0:
            return False

    return True

s = "(()())()"
locked = "11111111"
print(canBeValid(s, locked))
