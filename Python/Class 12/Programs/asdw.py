import random
for i in range(10):
    List=["Delhi","Mumbai","Chennai","Kolkata"]
    for y in range(4):
        x = random.randint(1,3)
        print(List[x],end="#")
    print()
