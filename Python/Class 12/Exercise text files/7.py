def DISPLAYWORDS():
    with open('WRITER.txt','r') as f:
        x=f.read().split()
        for i in x:
            if len(i)<4:
                print(i)
DISPLAYWORDS()
