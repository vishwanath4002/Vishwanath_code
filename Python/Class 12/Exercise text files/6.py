def countA():
    f=open('STORY.txt','r')
    c=0
    for i in f.readlines():
        if i[0]=='A':
            c+=1
    print(c)
    f.close()
