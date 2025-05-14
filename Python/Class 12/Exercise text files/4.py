def ISTOUPCPOUNT():
    f=open('WRITER.txt','r')
    x=f.read()
    print(x.count('IS')+x.count('TO')+x.count('UP'))
    f.close()
