with open('test.txt','w+') as f:
    f.write('hello')
    f.seek(0)
    print(f.read())
    print(f.read(2))
    
