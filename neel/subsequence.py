lis = [1,2,3,4,5]

s = ""
for i in range(len(lis)):
    s += chr(i+97)*lis[i]

sub_seq = []
sub_str = []

for i in range(len(s)-9):
    temp = s[i:i+10]
    sub_str.append(temp)
print(sub_str)

# for i in range(len(s)-9):
