# class NSTStudents:
#     school = "Newton"

#     def __init__(self,val1,val2="surname pata nahi"):
#         self.name = val1
#         self.surname =  val2
#         self.full_name = self.name + " " + self.surname

#     def setmarks(self , m = 0):
#         self.marks = m

# # s1 = NSTStudents(2)
# # s2 = NSTStudents(3)
# # print(s1.square)
# # print(s2.square)

# n1 = NSTStudents("neel")
# n2 = NSTStudents("arka")

# # print(n1.name)
# # print(n2.name)
# # print(n1.full_name)
# # print(n2.full_name)
# # print(n1.surname)
# # print(n2.surname)

# n1.setmarks(100)
# n2.setmarks()

# print(n1.marks)
# print(n2.marks)
# #print(NSTStudents.name)

# data = {'x': [10, 20], 'y': [30, 40]}
# for k in data.keys():
#     data[k] = data[k][::-1]
# print(data)

def fn(n):
    if n == 1:
        return 1
    return n ** 2 + fn(n - 1)

print(fn(3))
