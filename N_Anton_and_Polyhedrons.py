n = int(input())
dict = {
    "Tetrahedron": 4,
    "Cube": 6,
    "Octahedron": 8,
    "Dodecahedron": 12,
    "Icosahedron": 20
}

nee = 0
for i in range(n):
    a = input()
    nee += dict[a]

print(nee)