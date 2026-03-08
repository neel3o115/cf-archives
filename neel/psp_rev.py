def fun(num1, n, d):  
    for i in range(num1, 10*n):
        # print(i, i % n, (i**2) % n, "|", (i + d) , (i + d)% n, ((i + d) ** 2) % n)
        print(i % n, (i**2) % n, "|", (i + d)% n, ((i + d) ** 2) % n)
        # print((i**2) % n, "|" ,((i + d) ** 2) % n)
    return 
 

num1 = int(input())
n = int(input())


# def fun2(num1, n):
#     for i in range(num1, 10*n):
#         print(i % n, (i**2) % n)
#     return

fun(4, 3,2)

# print(bin(84)) 