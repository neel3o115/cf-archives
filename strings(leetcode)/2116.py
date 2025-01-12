s = "(()())"
locked = "111111"

nee = True
if len(s) % 2 != 0:
    nee = False

else:
    
    for i in range(len(s)):
        if i % 2 == 0 and s[i] == ")" and locked[i] == "1":
            nee = False
            break

        elif i % 2 != 0 and s[i] == "(" and locked[i] == "1":
            nee = False
            break

print(nee)
