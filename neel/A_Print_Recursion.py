n = int(input())

def fun(n):
    if n == 0:
        return
    print('I love Recursion')
    fun(n-1)

fun(n)