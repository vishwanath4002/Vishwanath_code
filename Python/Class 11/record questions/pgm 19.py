#19
d={}
while True:
    print('1.Add record.\n2.Display record.\n3.Search record.\n4.Update record.\n5.Exit.')
    c=int(input('\nEnter your choice (1/2/3/4/5) : '))

    print()
    
    if c==1:

        b=input('Enter the subject name : ')
        d[b]=input('Enter the teacher\'s name : ')

    elif c==2:

        if len(d)!=0:
            for x in d.keys():
                print('%s is taught by %s.'%(x,d[x]))
        else:
            print('There are no entries.')

    elif c==3:

        s=input('Enter the subject name to be searched : ')
        print()
        if s in d.keys():
            print('%s is taught by %s.'%(s,d[s]))
        else:
            print('Subject name entered is not present.')

    elif c==4:
        
        a=input('Enter the subject name whose teacher has to be updated : ')
        print()
        if a in d.keys():
            d[a]=input('Enter the new teacher\'s name ')
        else:
            print('Subject name entered does not exist.')

    elif c==5:

        break

    else:

        print('Invalid entry. Please try again.')
    print()
