def AEDISP():
    f=open('WRITER.txt','r')
    x=f.readlines()
    for i in x:
        if i[0]=='A' or i[0]=='E':
            print(i,end='')
    f.close()
AEDISP()

