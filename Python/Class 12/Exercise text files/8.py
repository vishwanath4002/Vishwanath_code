def RevText():
    with open('WRITER.txt','r') as f:
        x=''
        for i in f.read().split():
            if i[0]=='I':
                x+=i[::-1]+' '
            else:
                x+=i+' '
        print(x)
RevText()
