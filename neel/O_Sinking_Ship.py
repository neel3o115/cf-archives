t = int(input())
order = {"rat":[], "child":[], "man":[], "cap":[]}


for _ in range(t):
    name, type = input().split()

    if type == "rat":
        order["rat"].append(name)

    elif type == "child" or type == "woman":
        order["child"].append(name)

    elif type == "man":
        order["man"].append(name)
    
    else:
        order["cap"].append(name)

for value in order.values():
    for name in value:
        print(name)