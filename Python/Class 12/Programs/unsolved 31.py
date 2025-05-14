#Write a function Remove_Lowercase() that accepts two file names, and copies all lines that do not start with lowercase letter from the first file into the second file.
def Remove_Lowercase(x,y):
    with open(x+'.txt','r') as x:
        with open(y,'w') as y:
            for i in x.readlines():
                if i[0].islower():
                    y.write(i)
Remove_Lowercase('sample','y')
