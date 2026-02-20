# t = int(input())

# for _ in range(t):
#     n = int(input())
#     s = str(bin(n))
#     ss = list(s[2:])

#     print(ss)

#     count = 1
#     arr = []

#     for i in range(len(ss)):
#         if ss[i] == '1':
#             s[i] = 0 
#             arr.append(s)
#             count += 1
    
#     print(count)
#     print(arr)

def main():
    t = int(input())
    
    for _ in range(t):
        n = int(input())
        i = n + 1

        nee = set()

        while n != 0:
            n = n & i
            nee.add(n)
            i += 1

        print(len(nee))
        print(" ".join(map(str, sorted(nee))))


if __name__ == "__main__":
    main()
