#  gcd(a,b) = gcd(b, a % b) /  gcd(a, a % b)
#  gcd(a,b) = gcd(a, b - a)
#  gcd(a,0) = a
#  gcd(0,b) = b
#  gcd(0,0) = 0
#  when gcd(a,b) = 1 => a & b are coprime
#  time complexity =  O(log max(a,b))

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

a, b = map(int,input().split())
print(gcd(a,b))