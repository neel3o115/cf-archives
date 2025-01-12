digits = [9,9]

if digits[-1] != 9:
    digits[-1] += 1
else:
    for i in range(len(digits)-1, -1, -1):
        if digits[i] == 9:
            digits[i] = 0
            if i == 0:
                digits.insert(0, 1)
        else:
            digits[i] += 1
            break

print(digits)
