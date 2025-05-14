with open('1.txt','r') as 1:
    x=f1.read()
    with open('2.txt','w') as f2:
        f2.write(x.replace('  ',' '))
            
