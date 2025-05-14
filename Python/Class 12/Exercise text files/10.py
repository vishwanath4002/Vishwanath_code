def Count():
    with open('Report.txt','r') as f:
        c=0
        for i in f.readlines():
            if i[0]=='T' or i[0]=='M':
                c+=1
        print(c)
