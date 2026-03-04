class Fractional:

    def __init__(self,f):
        self.num =  int(f[:f.index("/")])
        self.deno = int(f[f.index("/")+1:])
        # self.fraction = 
    
    def add(f1,f2):
        new_num = (Fractional(f1).num * Fractional(f2).deno) + (Fractional(f2).num * Fractional(f1).deno)
        new_deno = (Fractional(f1).deno * Fractional(f2).deno)
        return str(new_num)+"/"+str(new_deno)



# n1 = Fractional("1/2")


# n2 = Fractional("3/5")


print(Fractional.add("1/2","3/5"))



# print(n1.add(n2))