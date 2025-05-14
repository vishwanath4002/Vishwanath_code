def moveCharacters():
    with open('sample.txt','r') as f:
        with open('lower.txt','w') as l:
            with open('upper.txt','w') as u:
                for i in f.read():
                    if i.islower():
                        l.write(i)
                    elif i.isupper():
                        u.write(i)
                    
