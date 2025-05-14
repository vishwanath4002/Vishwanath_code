with open('sasa.txt','w') as f:
    while True:
        f.write(input('Enter : ')+'\n')
        c=input('yes or no : ')
        if c=='no':
            break
