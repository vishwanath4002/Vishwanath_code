while True:
    c=int(input('\n1.to print Unique vowels in entered word.\n2.To print even length words in a string.\n3.Exit.\nEnter your choice (1,2,3) : '))
    l=[]
    if c==1:
        s=input('\nEnter the word : ')
        for i in s:
            if i.lower() in 'aeiou' and i not in l:
                l.append(i)
        print(l)
    elif c==2:
        s=input('\nEnter the string : ')
        for i in s.split():
            if len(i)%2==0:
                l.append(i)
        print(l)
    elif c==3:
        break
    else:
        print('\nInvalid entry. Please try again.')
        
