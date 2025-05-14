def loweralph():
    with open('BOOK.txt','r') as f:
        c=0
        for i in f.read():
            if i.islower():
                c+=1
        print(c)
